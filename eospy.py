from commands import getoutput

def eosls(directory, testMode=False):
  #command = "xrdfs root://cmsxrootd.fnal.gov ls %s" % directory
  command = "xrdfs root://cmseos.fnal.gov ls %s" % directory
  result = getoutput(command).splitlines()
  if testMode:
    print "command: ", command
    print "result:  ", result
  return result

if __name__ == "__main__":
  print "testing eosls..."
  eosls("/store/group/lpcboostres/vgTuples2018/GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", True)
