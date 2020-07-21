#!/bin/bash
for i in `ls -d configInis/*.ini | grep -v ignals`; do python makeCondorJunk.py -c $i -m 8 -x connect; done
for i in `ls -d configInis/*.ini | grep ignals`; do python makeCondorJunk.py -c $i -m 1 -x connect; done
