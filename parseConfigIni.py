def parseIni(configFile):
  from ConfigParser import RawConfigParser
  config = RawConfigParser()
  config.optionxform = str
  config.read(configFile)
  configDict =  dict([key, directory] for key, directory in config.items('dirs'))
  return configDict
