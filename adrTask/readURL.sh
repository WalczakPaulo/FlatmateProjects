#!/bin/sh
 > sites.txt


 for i in `seq 1 $1`
 do
	echo "Enter your URL: "
	read URL





	echo "$URL" >> sites.txt
 done 
