from os import getcwd, chmod
from argparse import ArgumentParser
from condorFactory import *

parser = ArgumentParser()
parser.add_argument("-c", "--configFile", dest = "configFile", 
                  help = "the name of the configuration file", required=True)
parser.add_argument("-d", "--doDirSplitting", dest = "doDirSplitting",
                  action="store_true", default=False,
                  help = "do the stuff in makeAllSmallerDirs.py")
parser.add_argument("-m", "--magicNumber", dest = "magicNumber", 
                  type = int, default=4,
                  help = "the magic number corresponding to the jdl's 'queue' setting")
parser.add_argument("-x", "--cluster", dest = "cluster", 
                  type = str, required=True,
                  help = "the cluster you want to run on, either 'lpc' or 'brux'")
parser.add_argument("-z", "--justCheck", dest = "justCheck", action="store_true", 
                  help = "just check file integrity, do not process")
args = parser.parse_args()


from parseConfigIni import parseIni
configDict =  parseIni(args.configFile)
print "\n---------\n"
print "making condor junk for", args.configFile
print "\n---------\n"

year = "nonsense"
if "2018" in args.configFile:
  year = 2018
elif "2017" in args.configFile:
  year = 2017
else:
  print "bad configFile. it should have a name with '2017' or '2018' in it."
  # this is here to force you to organize the names correctly.
  # the only thing it does in the code is to pass a year to runSmallify when runSmallify is used for the 'justCheck' step
  exit(1)

if args.doDirSplitting:
  from makeAllSmallerDirs import makeAllSmallerDirs
  makeAllSmallerDirs(configDict)


import datetime
today = datetime.date.today()

import glob, os

print "cleaning up..."
filelist = glob.glob(os.path.join("condor-area/*"))
for f in filelist:
    os.remove(f)
    print " > cleaned up", f
    
print "\n---------\n"
print "making new scripts and jdls..."

for dataset in configDict.keys():
  if not args.justCheck:
    scriptName = "condor-area/do-process%i_%s.sh" % (year, dataset)
    jdlName = "condor-area/sub-process%i_%s.jdl" % (year, dataset)
  else:
    scriptName = "condor-area/do-check%i_%s.sh" % (year, dataset)
    jdlName = "condor-area/sub-check%i_%s.jdl" % (year, dataset)
  outScript = open(scriptName, "w")
  chmod(outScript.name, 0o744) 
  outJdl = open(jdlName, "w")
  if args.magicNumber>0:
    outFileName = "smallified%i_%s_${1}.root" % (year, dataset)
    if args.justCheck:
      outScript.write(lpcScript("python runSmallify.py -z -y %i -i %s -o %s -m %i -c %s -q ${1}" % (year, configDict[dataset], outFileName, args.magicNumber, args.cluster), outFileName))
    else:
      outScript.write(lpcScript("python runSmallify.py -i %s -o %s -m %i -c %s -q ${1}" % (configDict[dataset], outFileName, args.magicNumber, args.cluster), outFileName))
    outJdl.write(queueJdl(outScript.name, args.magicNumber, True))
#  elif args.magicNumber==1:
#    outScript.write(simpleScript("python runSmallify.py %s smallified_%s.root" % (configDict[dataset], dataset), getcwd()))
#    outJdl.write(simpleJdl(outScript.name))
  outJdl.close()
  print "  > wrote", outJdl.name
  outScript.close()
  print "  > wrote", outScript.name

print "\n---------\n"
print "done."


