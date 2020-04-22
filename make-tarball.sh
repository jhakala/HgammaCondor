#!/bin/bash
if [ -f "smallifyTarball.tar" ]; then
    rm smallifyTarball.tar
fi

tar -h -cvf smallifyTarball.tar tarball-area
export _CONDOR_SCRATCH_DIR=$PWD/test-scratch
pushd $_CONDOR_SCRATCH_DIR
rm -rf *
ln -s ../smallifyTarball.tar .
popd
