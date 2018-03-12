/*	file:		MergeSort.cpp
 *	brief:		Merge sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>


void MergeSort(int *arr,int lhs,int rhs)
{
	if(lhs<rhs){
		int median=(lhs+rhs)>>1;
		MergeSort(arr,lhs,median);
		MergeSort(arr,median+1,rhs);
		Merge(arr,lhs,median,rhs);
	}
}

void Merge(int *arr,int lhs,int meds,int rhs)
{
	int n1=meds-lhs+1;
	int n2=rhs-meds;
	int *arrL=new int[n1];
	int *arrR=new int[n2];
	for(int ii=0;ii<n1;++ii)
		arrL[ii]=arr[lhs+ii];
	for(int jj=0;jj<n2;++jj)
		arrR[jj]=arr[meds+jj+1];
	int ii=0;
	int jj=0;
	int kk=lhs;
	while(ii<n1 && jj<n2){
		if(arrL[ii]>=arrR[jj])
			arr[kk++]=arrR[jj++];
		else
			arr[kk++]=arrL[ii++];
	}		
	while(ii<n1)
		arr[kk++]=arrL[ii++];
	while(jj<n2)
		arr[kk++]=arrR[jj++];
	delete[] arrL,arrR;
}
