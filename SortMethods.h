/*	file:		SortMethods.h
 *	brief:		Eight sort methods interface
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.11
 *	version:	v1.0.0
 */
#ifndef _SORT_METHODS_H_
#define _SORT_METHODS_H_

#include <iostream>
#include <fstream>
using namespace std;
const int N=10000;     		// Numbers of the seeds
const int Range=10000; 		// the range of the numbers
const int NBucket=1001;		// the numbers of the buckets

/* select sort method */
void SelectionSort(int *pArr);

/* Bubble sort method */
void BubbleSort(int *pArr);

/* Insert sort method */
void InsertSort(int *pArr);

/* Shell sort method */
void ShellSort(int *pArr);

/* Merge sort method */
void MergeSort(int *pArr, int nLeft, int nRight);
void Merge(int *pArr, int nLeft, int nMedian, int nRight);

/* MaxHeap sort method */
void HeapSort(int *pArr);
void BuildMaxHeap(int *pArr);
void MaxHeapify(int *pArr, int);

/* Quick sort method */
void QuickSort(int *pArr, int, int);
int Partition(int *pArr, int, int);
int RandomInRange(int, int);

/* Bucket sort method */
typedef struct BNode Node;
void SetBuckets(Node **pNodeData);
void BucketSort(int *pArr);
void InsertBuckets(int);
void PrintBuckets(Node **pNodeData);
Node* Insert(Node *pNodeData, int);

/* Swap inline function */
inline void Swap(int *pLeftValue, int *pRightValue)
{
	if(NULL == pLeftValue || NULL == pRightValue)
	{
		printf("param is null\n");
		return;
	}

	int nTmp = *pLeftValue;
	*pLeftValue  = *pRightValue;
	*pRightValue = nTmp;
}

#endif /* end of ifndef */