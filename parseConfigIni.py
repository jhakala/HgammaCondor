def parseIni(configFile):
  from ConfigParser import RawConfigParser
  config = RawConfigParser()
  config.optionxform = str
  config.read(configFile)
  configDict =  dict([key, directory] for key, directory in config.items('dirs'))
  return configDict

def getLocation(configFile):
  from ConfigParser import RawConfigParser
  config = RawConfigParser()
  config.optionxform = str
  config.read(configFile)
  if config.items('location'):
    configDict =  dict([key, directory] for key, directory in config.items('location'))
    if configDict["location"]:
      return configDict["location"]
  return "local"
