/*	file:		BubbleSort.cpp
 *	brief:		BubbleSort 
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.11
 *	version:	v1.0.0
 */

#include "SortMethods.h"

/* compare the nearby number */
void BubbleSort(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = 1; j < N - i; ++j)
		{
			if(pArr[j - 1] > pArr[j])
			{
				Swap(&pArr[j - 1], &pArr[j]);
			}
		}
	}
}