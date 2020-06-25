from commands import getoutput

def eosls(directory):
  command = "xrdfs root://cmsxrootd.fnal.gov ls %s" % directory
  return getoutput(command).splitlines()

def lpcEosInputs(inDirName):
  from subprocess import check_output
  import shlex
  eoslist = eosls(inDirName)
  inFiles = []
  allFiles
  
  print "doing round-robin inputs."
  iFile = 0
  for f in eoslist:
    if (iFile+queueNumber) % magicNumber == 0:
      if ".root" in f[-5:]:
        inFiles.append("root://cmsxrootd.fnal.gov//" + join(inDirName, f))
        allFiles.append("root://cmsxrootd.fnal.gov//" + join(inDirName, f))
        print "   > processing ", f
      else:
        print "   > skipping ", f, "since it is probably a log dir and not a .root file"
    else:
      allFiles.append("root://cmsxrootd.fnal.gov//" + join(inDirName, f))
      print "   > skipping", f
    iFile += 1
  return inFiles, allFiles

def findMatchingJdl(year, inDirName):
  from os.path import basename
  import glob

  bgJdls = glob.glob("jdls%i/*" % year)
  sampleName = basename(inDirName)
  for bgJdl in bgJdls:
    if sampleName in bgJdl:
      return bgJdl
  print "error, did not find matching jdl for inDir %s, sampleName %s in zgammasub/jdls%i" % (inDirName, sampleName, year)
  exit(1)

def getExpectedInputs(year, inDirName):
  with open(findMatchingJdl(year, inDirName), "r") as jdl:
    for line in jdl:
      if "Queue" in line:
        print "found line", line
        expectedJobs = int(line.split()[-1])
        return expectedJobs
  print "error, could not determine number of expected jobs for", inDirName


if __name__ == "__main__":
  from sys import argv
  from os import listdir
  from os.path import isfile, join
  from pprint import pprint
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
  parser.add_argument("-z", dest = "justCheck", action='store_true',
                      help = "don't process, just check integrity", required=False)
  parser.add_argument("-y", dest = "year", type=int,
                      help = "if doing -z, then a year is required, either 2017 or 2018", required=False)
  args = parser.parse_args()
  
  if args.justCheck and not (args.year in [2017, 2018]):
    print "invalid year selection for justCheck -- need to add '-y 2017' or '-y 2018'"
    exit(1)

  magicNumber = int(args.magicNumber)
  queueNumber = int(args.queueNumber)
  
  from ROOT import *
  chain = TChain("ntuplizer/tree")
  inputs = []
  allFiles = []
  if args.cluster == "lpc":
    inputs, allFiles = lpcEosInputs(args.inDirName)
  if args.cluster == "connect":
    inputs, allFiles = lpcEosInputs(args.inDirName)
  #elif args.cluster == "brux":
  #  bruxIsilonInputs(args.inDirName)
  else:
    print "invalid cluster"
    exit(1)

  missingFiles = []
  if args.justCheck:
    print "checking for missing input files"
    expectedInputs = getExpectedInputs(args.year, args.inDirName)
    missingFiles = range(0, expectedInputs)
    print "expected number of input files:", expectedInputs
    for f in allFiles:
      jobNumber = int(f.split("_")[-1].replace(".root", ""))
      print "found output file for job number", jobNumber
      missingFiles.remove(jobNumber)
    print "found missing files:", missingFiles
      

  print "checking input files for integrity"
  goodFiles = []
  badFiles = []
  for f in inputs:
    fileOK = False
    checkFile = TFile.Open(f)
    if not checkFile:
      badFiles.append(f)
    else:
      if checkFile.IsZombie():
        badFiles.append(checkFile.GetName())
      else:
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
  if not args.justCheck:
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
    with open("missingLog.txt", "w") as f:
      f.write(str(missingFiles))
    with open("badLog.txt", "w") as f:
      f.write(str(badFiles))
