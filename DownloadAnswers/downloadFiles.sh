#!/bin/bash
for c in {A..Z}
do
	url="staff.elka.pw.edu.pl/~rnowak2/dyd/zpr2017L/kol1zestA.cpp";
	wget -O "file$c.txt" $url;
done
