// Sorting_Algorithms_Test.cpp : 定义控制台应用程序的入口点。
//

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

int main()
{
	long lStart 	= 0;
	long lTimeUsed	= 0;
	int arr[N]={0};
	//cout<<"The input Numbers are-----------------------"<<endl;
	//OutputNumber(arr,N);
	cout<<"*******************************Begin Sorting!**********************"<<endl;

	InputNumber(arr,N);
	printf("\n<1>BubbleSort begins.\n");
	lStart = GetMilliSecond();
	BubbleSort(arr);	
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Bubble Sorted-time spending is %ld\n ms", lTimeUsed);

	InputNumber(arr,N);
	printf("\n<2>SelectionSort begins.\n");
	lStart = GetMilliSecond();
	SelectionSort(arr);	
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Selection Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arr,N);
	printf("\n<3>InsertSort begins.\n");
	lStart = GetMilliSecond();
	InsertSort(arr);
	lTimeUsed = GetMilliSecond() - lStart;
	printf("Insert Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arr,N);
	cout<<endl<<"<4>ShellSort begins."<<endl;
	lStart = GetMilliSecond();
	ShellSort(arr);
	printf("Shell Sorted-time spending is %ld ms\n", lTimeUsed);

	InputNumber(arr,N);
	cout<<endl<<"<5>MergeSort begins."<<endl;
	double TimeOfMergeSort;
	MergeSort_Test(arr,TimeOfMergeSort);
	cout<<"Total Sorted-time spending is "<<TimeOfMergeSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<6>MaxHeapSort begins."<<endl;
	double TimeOfMaxHeapSort;
	MaxHeap_Test(arr,TimeOfMaxHeapSort);
	cout<<"Total Sorted-time spending is "<<TimeOfMaxHeapSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<7>QuickSort begins."<<endl;
	double TimeOfQucikSort;
	QuickSort_Test(arr,TimeOfQucikSort);
	cout<<"Total Sorted-time spending is "<<TimeOfQucikSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<8>BucketSort begins."<<endl;
	double TimeOfBucketSort;
	BucketSort_Test(arr,TimeOfBucketSort);
	cout<<"Total Sorted-time spending is "<<TimeOfBucketSort<<"ms"<<endl;
	return 0;
}

