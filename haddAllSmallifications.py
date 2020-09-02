from parseConfigIni import parseIni
from sys import argv
from glob import glob
from subprocess import check_output
import os
import shlex

haddInis = [ "configInis/backgrounds2016.ini", "configInis/data2016.ini", 
             "configInis/backgrounds2017.ini", "configInis/data2017.ini", 
             "configInis/backgrounds2018.ini", "configInis/data2018.ini"]

signalInis =  [ "configInis/signals2016.ini", 
             "configInis/signals2017.ini", 
             "configInis/signals2018.ini"]

firstBackground = {}
dataDone = False

def haddFiles(files, directory, outFileName, doIt = True):

  if not os.path.exists(directory):
    print "initializing fresh directory", directory
    os.makedirs(directory)
  command = "hadd %s/%s" % (directory, outFileName)
  for fName in files:
    command += " " + fName
  print "\n-------------------------------------" 
  print command
  if doIt:
    print check_output(shlex.split(command))
  print "-------------------------------------\n"

def haddAllData(year, dataDone):
  if not dataDone:
    outFileName = "smallified_data%i.root" % year
    directory = "organize_smallifications%i/data" % year
    fNames = glob("smallified%i_data*%i*.root"%(year, year))
    haddFiles(fNames, directory, outFileName)

def haddOneSample(key, year, sampleType = "backgrounds"):
  topdir = "organize_smallifications%i"%year
  directory = os.path.join(topdir, sampleType)
  outFileName = "smallified%i_%s.root" % (year, key)
  if not os.path.exists(topdir):
    print "initializing fresh directory", directory
    os.makedirs(directory)
    
  fNames = glob("smallified%i_%s_*.root"%(year, key))
  haddFiles(fNames, directory, outFileName)
  
def getYear(configFile):
  if "2018" in configFile:
    return 2018
  elif "2017" in configFile:
    return 2017
  elif "2016" in configFile:
    return 2016
  else:
    print "year not found in data configFile name, exiting"
    exit(1)

def haddOneIni(configFile, dataDone):
  year = getYear(configFile)
  configDict = parseIni(configFile)

  for key in configDict.keys():
    if "data" in configFile:
      haddAllData(year, dataDone)
      dataDone = True
    else:
      haddOneSample(key, year)

def linkSignals(configFile):
  year = getYear(configFile)
  configDict = parseIni(configFile)
  sigDir = os.path.join("organize_smallifications%i"%year, "signals")
  if not os.path.exists(sigDir):
    print "initializing fresh directory", sigDir
    os.makedirs(sigDir)
  for key in configDict.keys():
    sourceName = "smallified%i_%s_0.root" % (year, key)
    targetName = "smallified%i_%s.root" % (year, key)
    print "linking", sourceName, "to", targetName
    os.link(sourceName, os.path.join(sigDir, targetName))
    
if __name__ == "__main__":
  from shutil import rmtree
  outDirs = ["organize_smallifications2016", "organize_smallifications2017", "organize_smallifications2018"]
  for outDir in outDirs:
    if os.path.exists(outDir):
      print "cleaning up old directory", outDir
      rmtree(outDir)
  for ini in haddInis:
    haddOneIni(ini, dataDone)
  for ini in signalInis:
    linkSignals(ini)
