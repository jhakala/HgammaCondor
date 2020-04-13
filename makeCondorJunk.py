from os import getcwd, chmod
from optparse import OptionParser
from condorFactory import *

parser = OptionParser()
parser.add_option("-c", "--configFile", dest = "configFile", 
                  help = "the name of the configuration file")
parser.add_option("-d", "--doDirSplitting", dest = "doDirSplitting",
                  action="store_true", default=False,
                  help = "do the stuff in makeAllSmallerDirs.py")
parser.add_option("-m", "--magicNumber", dest = "magicNumber", 
                  type = int, default=4,
                  help = "the magic number corresponding to the jdl's 'queue' setting")
(options, args) = parser.parse_args()

if options.configFile is None:
  print "please specify a configuration file with the -c option"
  exit(1)

from parseConfigIni import parseIni
configDict =  parseIni(options.configFile)

if options.doDirSplitting:
  from makeAllSmallerDirs import makeAllSmallerDirs
  makeAllSmallerDirs(configDict)


import datetime
today = datetime.date.today()

for dataset in configDict.keys():
  outScript = open("h_%s.sh" % dataset, "w")
  chmod(outScript.name, 0o744) 
  outJdl = open("c_%s.jdl" % dataset, "w")
  if options.magicNumber>1:
    outFileName = "smallified_%s_${1}.root" % dataset
    outScript.write(lpcScript("python runSmallify.py %s %s %i ${1}" % (configDict[dataset], outFileName, options.magicNumber), outFileName))
    outJdl.write(queueJdl(outScript.name, options.magicNumber, True))
  elif options.magicNumber==1:
    outScript.write(simpleScript("python runSmallify.py %s smallified_%s.root" % (configDict[dataset], dataset), getcwd()))
    outJdl.write(simpleJdl(outScript.name))
  outJdl.close()
  outScript.close()


