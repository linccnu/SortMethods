#########################################################################
# Author: 0054
# Created Time: 2018年03月13日 星期二 20时53分04秒
# File Name: makeAll.sh
# Description:create build&bin file folder and compiler the source codes
#########################################################################
#!/bin/bash

cur_dir=$(cd `dirname $0`;pwd)
echo "dirname:$cur_dir"
exec_file=$(basename $0)
echo $exec_file
echo `basename $0`

bin_file="$cur_dir/bin"
build_file="$cur_dir/build"

#cmake and make executable file, excute it!
ProcDemo()
{
	if [ ! -d "$bin_file" ];then
		echo "---bin folder is not exit in dir:$cur_dir, create it!"
		mkdir -p $bin_file
		#chmod 777 $bin_file
	fi

	if [ ! -d "$build_file" ];then
		echo "---build folder is not exit in dir:$cur_dir, create it!"
		mkdir -p $build_file
		#chmod 777 $build_file
	fi

	#begin to build the makefile and executable file
	echo ""
	cd $build_file
	cmake ..
	make
	echo ""
	echo "---compiler source codes and make executable file ok!"
	echo ""
	
	#begin to excute the executable file
	cd $bin_file
	gdb ./demo
	echo ""
}


#clear the invalid files or folders
Clear()
{
	
	if [ -d "$bin_file" ];then
		rm -rf $bin_file
		echo "---delete folder:bin ok."
	fi

	if [ -d "$build_file" ];then
		rm -rf $build_file
		echo "---delete folder:build ok."
	fi
}


#echo "************begin to excute**********"
echo "*************选择执行类型**************"
echo "*********0---生成可执行文件并执行******"
echo "*********1---清空无效的文件夹**********"

read -p "请选择操作类型:" type
case $type in
	0)
		echo "---select to compiler executable file and excute."
		ProcDemo
		;;
	1)
		echo "---select to remove the invalid folders."
		Clear
		;;
	*)
		echo "#######################################"
		echo "ERROR:输入类型($type) 不匹配，无法执行!"
		echo "#######################################"
esac
