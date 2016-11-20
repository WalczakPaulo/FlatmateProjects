#!/bin/sh

#for every line in sites.txt download images...

for line in `cat sites.txt`; do

#stripped url contains the name of website
#target_folder contains the path to the new folder to be created_

	stripped_url=`echo $line| cut -c8-`
	target_folder="downloads/`echo $stripped_url|sed 's/\//_/g'`"
#printf out on the screen some messages
echo $stripped_url
echo ""
echo ""
echo ""
echo "Scraping $stripped_url"
echo "-------------------------"
echo ">creating folder.."
echo $targer_folder

#making new directory folder for images
mkdir -p $target_folder
echo "> scraping $stripped_url"

#heres the body and the engine of downloading images..
wget -e robots=off \
 -H -nd -nc -np \
 --recursive -p \
 --level=1\
 --accept jpg,jpeg,png,gif \
 --convert-links -N \
 --limit-rate=200k \
 --wait 0.1 \
 -P $target_folder $stripped_url
echo ""
echo ""
echo "> Finished scraping $stripped_url"
done

#clear the sites.txt file
> sites.txt 
