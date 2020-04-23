from parseConfigIni import parseIni
from sys import argv
from glob import glob
from subprocess import check_output
import shlex


inputInis = ["configInis/data.ini"]
#inputInis = ["configInis/backgrounds.ini"]

def haddOneSample(key, sampleType = "backgrounds"):
  outFileName = "smallified_%s.root" % key
  command = "hadd organize_smallifications/%s/%s" % (sampleType, outFileName)
  for fName in glob("smallified_%s_*.root"%key):
    command += " " + fName
  print "\n-------------------------------------" 
  print command
  print check_output(shlex.split(command))
  print "-------------------------------------\n"
  

def haddOneIni(configFile):
  configDict = parseIni(configFile)
  for key in configDict.keys():
    if "data" in configFile:
      haddOneSample(key, "data")
    else:
      haddOneSample(key)

if __name__ == "__main__":
  for ini in inputInis:
    haddOneIni(ini)
