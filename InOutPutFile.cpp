/*	file:		InOutPut.cpp
 *	brief:		InOutPut implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include <iostream>
#include "SortMethods.h"
#include "InOutPut.h"

void InputNumber(int *arr,int N)
{
	if(arr==NULL)
		return;
	for(int ii=0;ii<N;++ii)
		arr[ii]=rand()%Range;
}

void OutputNumber(int *arr,int N)
{
	cout<<"The Sorted Numbers are: "<<endl;
	for(int ii=0;ii<N;++ii)
		cout<<arr[ii]<<'\t';
	cout<<endl;
}

void FileOutPut(int *arr,const char *file)
{
	fstream fout;
	fout.open(file);
	for(int ii=0;ii<N;++ii)
		fout<<arr[ii]<<'\t';
	fout.close();
}
