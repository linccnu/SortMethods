/*	file:		HeapSort.cpp
 *	brief:		Max Heap sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>

int nHeapSize = N;

void HeapSort(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}
	BuildMaxHeap(pArr);
	for(int ii = nHeapSize - 1; ii >= 1; --ii)
	{
		Swap(&pArr[0], &pArr[ii]);
		nHeapSize -= 1;
		MaxHeapify(pArr,0);
	}
}

void BuildMaxHeap(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}
	int lenflag = (nHeapSize >> 1) - 1;
	for(int ii = lenflag; ii >= 0; --ii)
	{
		MaxHeapify(pArr, ii);
	}	
}

void MaxHeapify(int *pArr,int nFlag)
{
	int nLeftchild  = 2 * nFlag + 1;
	int nRightchild = 2 * nFlag + 2;
	int nLargest 	= 0;
	if(nLeftchild < nHeapSize && pArr[nLeftchild] > pArr[nFlag])
	{
		nLargest = nLeftchild;
	}
	else
	{
		nLargest = nFlag;
	}
		
	if(nRightchild < nHeapSize && pArr[nRightchild] > pArr[nLargest])  //!!!这里比较的是右结点和当前最大结点之间的关系 arr[nRightchild]>arr[nFlag] 
	{
		nLargest = nRightchild;
	}
		
	if(nLargest != nFlag)
	{
		Swap(&pArr[nLargest], &pArr[nFlag]);
		MaxHeapify(pArr, nLargest);
	}
}
