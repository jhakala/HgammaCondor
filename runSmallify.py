from sys import argv
from os import listdir
from os.path import isfile, join
from pprint import pprint
from ROOT import *
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument("-i", dest = "inDirName",
                    help = "input directory", required=True)
parser.add_argument("-o", dest = "outputName",
                    help = "output filename", required=True)
parser.add_argument("-m", dest = "magicNumber",
                    help = "magic number", required=True)
parser.add_argument("-q", dest = "queueNumber",
                    help = "queue number", required=True)
parser.add_argument("-c", dest = "cluster",
                    help = "cluster", required=True)
args = parser.parse_args()

magicNumber = int(args.magicNumber)
queueNumber = int(args.queueNumber)

chain = TChain("ntuplizer/tree")
inFiles = []

def lpcEosInputs(inDirName):
  from subprocess import check_output
  import shlex
  eoslist = check_output(shlex.split("xrdfs root://cmseos.fnal.gov ls %s" % inDirName)).splitlines()
  
  print "doing round-robin inputs."
  iFile = 0
  for f in eoslist:
    if (iFile+queueNumber) % magicNumber == 0:
      inFiles.append("root://cmseos.fnal.gov//" + join(inDirName, f))
      print "   > processing ", f
    else:
      print "   > skipping", f
    iFile += 1


def bruxIsilonInputs(inDirName):
  isilonList = listdir(inDirName)
  
  print "doing round-robin inputs."
  iFile = 0
  for f in isilonList:
    if (iFile+queueNumber) % magicNumber == 0:
      if isfile(join(inDirName, f)):
        inFiles.append(join(inDirName, f))
        print "   > processing ", f
      else:
        print "   > ignoring directory ", f
    else:
      print "   > skipping", f
    iFile += 1

if args.cluster == "lpc":
  lpcEosInputs(args.inDirName)
elif args.cluster == "brux":
  bruxIsilonInputs(args.inDirName)
else:
  print "invalid cluster"
  exit(1)
print "checking input files for integrity"
goodFiles = []
badFiles = []
for f in inFiles:
  fileOK = False
  checkFile = TFile.Open(f)
  if "ntuplizer" in checkFile.GetListOfKeys():
    if ("tree" in checkFile.Get("ntuplizer").GetListOfKeys()) and ("hCounter" in checkFile.Get("ntuplizer").GetListOfKeys()):
      fileOK = True
  if fileOK:
    goodFiles.append(checkFile.GetName())
  else:
    badFiles.append(checkFile.GetName())

print "found bad files:", badFiles



print "good inFiles:"
pprint(goodFiles)
for inFile in goodFiles:
  chain.Add(inFile)
print "TChain has NEntries: %i" % chain.GetEntries()
compRet = gSystem.CompileMacro("smallify.C", "gOck")
print "smallify.C compile return code:", compRet
loadRet = gSystem.Load('smallify_C')
print "smallify_C.so load return code:", loadRet
gSystem.Load('smallify_C')
smallifier = smallify(chain)
smallifier.Loop(args.outputName)

newHcounter = TH1I("hCounter", "Events counter", 5,0,5)
for inFileName in goodFiles:
  print "going back to collect hCounter from:"
  print inFileName
  inFile = TFile.Open(inFileName)
  #print "file %s has %i events." % ( inFileName, inFile.Get("ntuplizer/hCounter").GetBinContent(1) )
  newHcounter.SetBinContent(1, newHcounter.GetBinContent(1) + inFile.Get("ntuplizer/hCounter").GetBinContent(1))
  #print " -->total = %i" % newHcounter.GetBinContent(1)
outfile = TFile(args.outputName, "UPDATE")
outfile.cd("ntuplizer")
newHcounter.Write()
outfile.Close()

if len(badFiles) > 0:
  with open("badLog.txt", "w") as f:
    f.write(str(badFiles))
