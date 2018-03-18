/*	file:		ShellSort.cpp
 *	brief:		Shell sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include "SortMethods.h"

void ShellSort(int *arr)
{
	if(NULL == arr)
	{
		printf("param is null.\n");
		return;
	}

	int ii,increment,flag,temp;
	for(increment=N/2;increment>0;increment/=2)
		for(ii=increment;ii<N;++ii){
			temp=arr[ii];
			flag=ii-increment;
			while(flag>=0 && arr[flag]>temp){
				arr[flag+increment]=arr[flag];
				flag-=increment;
			}
			flag+=increment;
			arr[flag]=temp;
		}
}
