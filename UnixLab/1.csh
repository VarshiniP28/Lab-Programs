#!/bin/csh
if($#argv == 0) then
	echo -n " Enter file name: "
	set name = $<
else
	set name = $*
endif
set var1 = `ls -l $name | grep -o ^.`
echo $var1
if(-e $name) then
	echo "$name exists"
	switch ($var1)
		case -: 
			echo "$name is an REGULAR file"
			breaksw
		case t: 
			echo "$name is a DIRECTORY file"
			breaksw
                case p: 
			echo "$name is a FIFO file"
			breaksw
		case c: 
			echo "$name is a Character device file"
			breaksw
		case b: 
			echo "$name is a Block device file"
			breaksw
		case l: 
			echo "$name is a SYMBOLIC LINK file"
			breaksw
		default: 
			echo "$name Unrecognizable type of file"
			breaksw
	endsw
else
	echo "$name does NOT exist"
endif
