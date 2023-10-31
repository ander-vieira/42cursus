#!/bin/bash
if [ $# -ge 2 ]
then
	echo "Cloning repo..."
	rm -rf ~/42eval
	mkdir ~/42eval
	cp -rf $1/test/ ~/42eval/test
	cp -f $1/test.sh ~/42eval/
	git clone $2 ~/42eval/repo
else
	echo "Usage: $0 <project> <git repo>"
fi