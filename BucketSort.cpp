/*	file:		BucketSort.cpp
 *	brief:		Bucket Heap sort methods implement
 *
 *	author:		zhonglin
 *  email:		lin_nudt0625@163.com
 *	date:		2018.3.12
 *	version:	v1.0.0
 */

#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>

struct BNode{
	int num;
	struct BNode *next;
};
typedef struct BNode Node;
Node **arrB=(Node**)malloc(NBucket*sizeof(Node*));

void SetBuckets(Node **arrB)
{
	for(int ii=0;ii<NBucket;++ii){
		arrB[ii]=(Node *)malloc(sizeof(Node));
		arrB[ii]->next=NULL;
		arrB[ii]->num=0;
	}
}
void BucketSort(int *arr)
{
	if(arr == NULL)
	{
		printf("param is null\n");
		return;
	}
	for(int ii=0;ii<N;++ii)
		InsertBuckets(arr[ii]);
}

void InsertBuckets(int temp)
{
	Node *pNode=(Node *)malloc(sizeof(Node));
	pNode->next=NULL;
	pNode->num=temp;

	int flag=temp/(NBucket-1);
	Node *ptr=arrB[flag];
	if(ptr->next==NULL)
		ptr->next=pNode;
	else
		arrB[flag]=Insert(pNode,flag);
}

Node *Insert(Node *pNode,int flag)
{
	Node *phead=arrB[flag];
	Node *ptr=phead;
	while(ptr->next!=NULL && ptr->next->num <=pNode->num)
		ptr=ptr->next;
	pNode->next=ptr->next;
	ptr->next=pNode;
	return phead;
}

void PrintBuckets(Node **arrB)
{
	Node *ptr=NULL;
	for(int jj=0;jj<NBucket ;++jj){
		ptr=arrB[jj];
		while(ptr->next!=NULL){
			ptr=ptr->next;
			cout<<ptr->num<<'\t';
		}
	}
	cout<<endl;
}
