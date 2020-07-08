from parseConfigIni import parseIni
from sys import argv
from glob import glob
from subprocess import check_output
import os
import shlex


#inputInis = ["configInis/data.ini"]
#inputInis = ["configInis/backgrounds.ini"]
inputInis = ["configInis/backgrounds2018.ini", "configInis/data2018.ini"]
dataDone = False

def haddFiles(files, directory, outFileName, doIt = True):

  if not os.path.exists(directory):
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
    fNames = glob("smallified%i_data%i*.root"%(year, year))
    haddFiles(fNames, directory, outFileName)

def haddOneSample(key, year, sampleType = "backgrounds"):
  outFileName = "smallified%i_%s.root" % (year, key)
  #command = "hadd organize_smallifications/%s/%s" % (sampleType, outFileName)
  directory = "organize_smallifications%i/%s" % (year, sampleType)
  fNames = glob("smallified%i_%s_*.root"%(year, key))
  haddFiles(fNames, directory, outFileName)
  

def haddOneIni(configFile, dataDone):
  configDict = parseIni(configFile)
  if "2018" in configFile:
    year = 2018
  elif "2017" in configFile:
    year=2017
  else:
    print "year not found in data configFile name, exiting"
    exit(1)

  for key in configDict.keys():
    if "data" in configFile:
      haddAllData(year, dataDone)
      dataDone = True
    else:
      haddOneSample(key, year)

if __name__ == "__main__":
  for ini in inputInis:
    haddOneIni(ini, dataDone)
