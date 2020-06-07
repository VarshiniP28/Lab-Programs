#!/bin/csh

echo -n "Enter the file name -- "
set name = $<

set count=`wc -l $name`
echo "Number of lines in $name = $count"
