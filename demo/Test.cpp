/*	file:		Test.cpp
 *	brief:		Test demo
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.11
 *	version:	v1.0.0
 */

#include <cstring>
#include <sys/time.h>
#include "SortMethods.h"
#include "InOutPut.h"

/* 计算当前系统时间 */
long GetMilliSecond()
{
	struct timeval stTime;
	memset(&stTime, 0x0, sizeof(stTime));
	gettimeofday(&stTime, NULL);

	return stTime.tv_sec*1000 + stTime.tv_usec/1000;
}

/* 主函数入口处 */
int main()
{
	long 	lStart 		= 0;
	long 	lTimeUsed	= 0;

	int 	arrNumber[N];
	memset(arrNumber, 0x0, sizeof(arrNumber));
	cout<<"*******************************Begin Sorting!**********************"<<endl;

	InputNumber(arrNumber, N);
	printf("\n<1>BubbleSort begins.\n");
	lStart = GetMilliSecond();
	BubbleSort(arrNumber);	
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Bubble Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<2>SelectionSort begins.\n");
	lStart = GetMilliSecond();
	SelectionSort(arrNumber);	
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Selection Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<3>InsertSort begins.\n");
	lStart = GetMilliSecond();
	InsertSort(arrNumber);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Insert Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<4>ShellSort begins.\n");
	lStart = GetMilliSecond();
	ShellSort(arrNumber);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Shell Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<5>MergeSort begins.\n");
	lStart = GetMilliSecond();
	MergeSort(arrNumber, 0, N-1);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Merge Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<6>MaxHeapSort begins.\n");
	lStart = GetMilliSecond();
	HeapSort(arrNumber);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("MaxHeap Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<7>QuickSort begins.\n");
	lStart = GetMilliSecond();
	QuickSort(arrNumber, 0, N-1);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Quick Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arrNumber, N);
	printf("\n<8>BucketSort begins.\n");
	lStart = GetMilliSecond();
	BucketSort(arrNumber);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Bucket Sorted-time spending is %ld ms\n", lTimeUsed);

	return 0;
}

