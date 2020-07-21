from os.path import basename
def simpleJdl(scriptName):
  return """universe = vanilla
Executable = {0} 
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Notification = Error
 
Output = condorLogs/log.{1}.$(Cluster).$(Process).stdout
Error = condorLogs/log.{1}.$(Cluster).$(Process).stderr
Log = condorLogs/log.{1}.$(Cluster).$(Process).condorlog

Queue 1
""".format(scriptName, basename(scriptName))

def queueJdl(scriptName, queue, lpcMode=False):
  output= """universe = vanilla
Executable = %s 
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Notification = Error
""" % scriptName

  if lpcMode:
    output+="""
transfer_input_files = smallifyTarball.tar
"""

  output+="""
arguments = $(Process)
+REQUIRED_OS="rhel7"
+DesiredOS = REQUIRED_OS 

+DESIRED_Sites="T3_US_Baylor,T0_CH_CERN,T2_CH_CERN,T2_CH_CERN_AI,T2_CH_CERN_HLT,T2_US_Caltech,T3_US_Colorado,T3_US_Cornell,T3_US_FIT,T3_US_FNALLPC,T3_US_Omaha,T3_US_JHU,T3_US_Kansas,T2_US_MIT,T3_US_NotreDame,T2_US_Nebraska,T3_US_NU,T3_US_OSU,T3_US_Princeton_ICSE,T2_US_Purdue,T3_US_Rice,T3_US_Rutgers,T3_US_MIT,T3_US_NERSC,T3_US_SDSC,T3_CH_CERN_CAF,T3_US_FIU,T3_US_FSU,T3_US_OSG,T3_US_TAMU,T3_US_TTU,T3_US_UCD,T3_US_UCSB,T2_US_UCSD,T3_US_UMD,T3_US_UMiss,,T2_US_Vanderbilt,T2_US_Wisconsin"
 
Output = condorLogs/log.{1}.$(Cluster).$(Process).stdout
Error = condorLogs/log.{1}.$(Cluster).$(Process).stderr
Log = condorLogs/log.{1}.$(Cluster).$(Process).condorlog

Queue {2}
""" .format(scriptName, basename(scriptName),  queue)

  return output

def simpleScript(incantation, pwd):
  return """#!/bin/bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd %s
eval `scramv1 runtime -sh`
%s""" % ( pwd, incantation )


def lpcScript(incantation, outFileName):
  return """#!/bin/bash
if [[ $# -ne 1 ]] ; then
    echo "missing queue number"
    exit 1
fi
cd ${_CONDOR_SCRATCH_DIR}
echo "working in condor scratch dir: $_CONDOR_SCRATCH_DIR"
tar -xf smallifyTarball.tar
if [[ $? -ne 0 ]] ; then
    exit 1
fi
cd tarball-area
source /cvmfs/cms.cern.ch/cmsset_default.sh
scramv1 project CMSSW CMSSW_10_2_22
pushd CMSSW_10_2_22/src
eval `scramv1 runtime -sh`
popd
export XrdSecGSISRVNAMES=cmseos.fnal.gov
%s
if [[ $? -ne 0 ]] ; then
    exit 1
fi
if [ -f "%s" ]; then
  mv %s ${_CONDOR_SCRATCH_DIR}
fi
if [ -f "badLog.txt" ]; then
  mv badLog.txt ${_CONDOR_SCRATCH_DIR}/badLog-%s.txt
fi
if [ -f "missingLog.txt" ]; then
  mv missingLog.txt ${_CONDOR_SCRATCH_DIR}/missingLog-%s.txt
fi
cd ${_CONDOR_SCRATCH_DIR}
rm -rf tarball-area
rm -f smallifyTarball.tar
echo done""" % ( incantation, outFileName, outFileName, outFileName, outFileName)
