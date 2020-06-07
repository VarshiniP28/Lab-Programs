#!/bin/csh
echo -n "Enter the string :"
set name=$<
echo -n "Enter the starting position for substring extraction : "
set s=$<
echo -n "Enter the ending position : "
set e=$<
echo -n "The extracted substring is "
set var1=`echo $name|cut -c$s-$e`
echo -n $var1
