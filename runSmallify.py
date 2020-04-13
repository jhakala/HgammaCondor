from sys import argv
from os import listdir
from os.path import isfile, join
from pprint import pprint
from ROOT import *

if len(argv) != 5:
  print "please supply four arguments to the macro: the input directory, the output filename, the magic number, and the queue number"
  exit(1)

inDirName = argv[1]
outputName = argv[2]
magicNumber = int(argv[3])
queueNumber = int(argv[4])

chain = TChain("ntuplizer/tree")
inFiles = []

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
smallifier.Loop(outputName)

newHcounter = TH1I("hCounter", "Events counter", 5,0,5)
for inFileName in goodFiles:
  print "going back to collect hCounter from:"
  print inFileName
  inFile = TFile.Open(inFileName)
  #print "file %s has %i events." % ( inFileName, inFile.Get("ntuplizer/hCounter").GetBinContent(1) )
  newHcounter.SetBinContent(1, newHcounter.GetBinContent(1) + inFile.Get("ntuplizer/hCounter").GetBinContent(1))
  #print " -->total = %i" % newHcounter.GetBinContent(1)
outfile = TFile(outputName, "UPDATE")
outfile.cd("ntuplizer")
newHcounter.Write()
outfile.Close()

if len(badFiles) > 0:
  with open("badLog.txt", "w") as f:
    f.write(str(badFiles))
