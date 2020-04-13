def simpleJdl(scriptName):
  return """universe = vanilla
Executable = %s 
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Notification = Error
 
Output = condorLogs/log.%s.$(Cluster).$(Process).stdout
Error = condorLogs/log.%s.$(Cluster).$(Process).stderr
Log = condorLogs/log.%s.$(Cluster).$(Process).condorlog

Queue 1
""" % (scriptName, scriptName, scriptName, scriptName)

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
 
Output = condorLogs/log.{0}.$(Cluster).$(Process).stdout
Error = condorLogs/log.{0}.$(Cluster).$(Process).stderr
Log = condorLogs/log.{0}.$(Cluster).$(Process).condorlog

Queue {1}
""" .format(scriptName, queue)

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
tar -xvf smallifyTarball.tar
if [[ $? -ne 0 ]] ; then
    exit 1
fi
cd tarball-area
source /cvmfs/sft.cern.ch/lcg/views/LCG_95a/x86_64-slc6-gcc8-opt/setup.sh
%s
if [[ $? -ne 0 ]] ; then
    exit 1
fi
mv %s ${_CONDOR_SCRATCH_DIR}
if [ -f "badLog.txt" ]; then
  mv badLog.txt ${_CONDOR_SCRATCH_DIR}/badLog-%s.txt
fi
cd ${_CONDOR_SCRATCH_DIR}
rm -rf tarball-area
rm -f smallifyTarball.tar
echo done""" % ( incantation, outFileName, outFileName)
