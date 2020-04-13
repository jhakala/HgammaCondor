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
args = parser.parse_args()


from parseConfigIni import parseIni
configDict =  parseIni(args.configFile)

if args.doDirSplitting:
  from makeAllSmallerDirs import makeAllSmallerDirs
  makeAllSmallerDirs(configDict)


import datetime
today = datetime.date.today()

for dataset in configDict.keys():
  outScript = open("h_%s.sh" % dataset, "w")
  chmod(outScript.name, 0o744) 
  outJdl = open("c_%s.jdl" % dataset, "w")
  if args.magicNumber>1:
    outFileName = "smallified_%s_${1}.root" % dataset
    outScript.write(lpcScript("python runSmallify.py -i %s -o %s -m %i -c %s -q ${1}" % (configDict[dataset], outFileName, args.magicNumber, args.cluster), outFileName))
    outJdl.write(queueJdl(outScript.name, args.magicNumber, True))
  elif args.magicNumber==1:
    outScript.write(simpleScript("python runSmallify.py %s smallified_%s.root" % (configDict[dataset], dataset), getcwd()))
    outJdl.write(simpleJdl(outScript.name))
  outJdl.close()
  outScript.close()


