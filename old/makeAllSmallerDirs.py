def makeAllSmallerDirs(configDict):
  from makeSmallerDirs import breakDirs
    
  for dataset in configDict:
    breakDirs(configDict[dataset], dataset)

if __name__ == "__main__":
  from sys import argv
  from ConfigParser import RawConfigParser
  config = RawConfigParser()
  config.optionxform = str
  config.read(argv[1])
  dirs = dict([key, directory] for key, directory in config.items('dirs'))

  makeAllSmallerDirs(dirs)


