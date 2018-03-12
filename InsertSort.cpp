/*	file:		InsertSort.cpp
 *	brief:		Insert sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.11
 *	version:	v1.0.0
 */

#include "SortMethods.h"

void InsertSort(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}

	int nIndex 	= 0;
	int nTemp	= 0;
	for(int ii = 1; ii < N; ++ii)
	{
		nIndex  = ii - 1;
		nTemp	= pArr[ii];
		
		while(nIndex >= 0 && pArr[nIndex] > nTemp)
		{
			pArr[nIndex + 1] = pArr[nIndex];
			--nIndex;
		}
		pArr[nIndex + 1] = nTemp;
	}
}
