#!/bin/csh

echo "Enter the file name "
set a=$<
if(-e $a) then
 echo "File exists"
else
 echo "File doesn't exist"
 exit
endif

ls -Rl $a
echo "Enter permissions"
set p=$<
ls -Rl $a|cut -b 1-100 | grep $p

