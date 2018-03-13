/*	file:		QuickSort.cpp
 *	brief:		Quick sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>

void QuickSort(int *pArr, int nStart, int nEnd)
{
	if(nStart == nEnd)
		return;
	int nIndex = Partition(pArr, nStart, nEnd);

	if(nStart < nIndex)
	{
		QuickSort(pArr, nStart, nIndex-1);
	}
		
	if(nIndex < nEnd)
	{
		QuickSort(pArr, nIndex+1, nEnd);
	}
		
}


int Partition(int *pArr, int nStart, int nEnd)
{
	if(pArr == NULL || nStart < 0 ||nEnd >= N)
	{
		printf("param is null.\n");
		return -1;
	}
	int nIndex = RandomInRange(nStart, nEnd);
	Swap(&pArr[nIndex], &pArr[nEnd]);

	int nFlag = nStart - 1;
	for(int ii = nStart; ii < nEnd; ++ii)
	{
		if(pArr[ii] < pArr[nEnd])
		{
			++nFlag;
			if(nFlag != ii )
			{
				Swap(&pArr[nFlag], &pArr[ii]);
			}
		}
	}

	++nFlag;
	Swap(&pArr[nFlag], &pArr[nEnd]);

	return nFlag;
}


int RandomInRange(int nStart, int nEnd)
{
	int nRange = 0;
	int nFlag  = 0;
	nRange = nEnd - nStart;
	nFlag = rand()%nRange + nStart;

	return nFlag;
}
