#########################################################################
# Author: 0054
# Created Time: 2018年03月13日 星期二 20时53分04秒
# File Name: config.sh
# Description: 
#########################################################################
#!/bin/bash

bin_file="$PWD/bin"
build_file="$PWD/build"

if [ ! -d "$bin_file" ];then
	mkdir -p $bin_file
	#chmod 777 $bin_file
else
	rm -rf $bin_file/*
	echo "delete all the files in $bin_file"
fi

if [ ! -d "$build_file" ];then
	mkdir -p $build_file
	#chmod 777 $build_file
else
	rm -rf $build_file/*
	echo "delete all the files in $build_file"
fi
