#!/bin/bash
if [ $# -ge 2 ]
then
	echo "---------- Cloning repo..."
	rm -rf ~/42repo
	git clone $2 ~/42repo
	rm -rf ~/42repo/*
	cp -rf $1/repo/* ~/42repo
	cp -f $1/vogignore ~/42repo/.gitignore
	cd ~/42repo
	echo "---------- Committing files..."
	git config user.name andeviei
	git config user.email andeviei@student.42urduliz.com
	git add .
	git commit -m "Upload to vogsphere"
	echo "---------- Pushing to remote..."
	git push
else
	echo "Usage: $0 <project> <git repo>"
fi