#include<stdio.h>
#include<stdlib.h>

typedef struct heap_t
{
	int *arr;			//	arr指针指向的是存放堆数据的数组。
	int heapMaxIndex;	//	heapMaxIndex是数组最大的序号。如数组定义为a[10]，那么heapMaxIndex的值应该为9.
	int arrLength;		//	数组的长度

} Heap;


void maxHeapify(Heap *hp, unsigned int nodei)	//	让一个数组变成一个符合堆性质的数组	时间复杂度为O(log(n))
{
	unsigned int l = (nodei+1) << 1 - 1;	//	left child = 2i-1, -1 ?:arr[0..n-1]
	unsigned int r = (nodei+1) << 1 ;		//	right child = 2i
	unsigned int largest = 0;
	int heapMaxI = hp->heapMaxIndex;

	if(l <= heapMaxI && hp->arr[l] > hp->arr[nodei])
		largest = l ;
	else
		largest = nodei ;

	if(r <= heapMaxI && hp->arr[r] > hp->arr[largest])
		largest = r ;

	if(largest!=nodei)
	{
		//exchange
		int tmp ;
		tmp = hp->arr[largest];
		hp->arr[largest] = hp->arr[nodei];
		hp->arr[nodei] = tmp;

		maxHeapify(hp,largest);
	}
	else
	{
		return ;
	}
}

Heap *createHeap(int* arrp, int arrLength, Heap* heap)
{
	int i;
	heap->arr = arrp;
	heap->heapMaxIndex = arrLength-1;
	heap->arrLength = arrLength;

//for an heap a[0..n-1]; a[(n/2)..n-1] all are leaves
	for(i = arrLength>>1-1; i >=0; i--)
		maxHeapify(heap,i);
	return heap;
}

void heapSort(Heap *hp)
{
	int tmp;
	int last;
	while(hp->heapMaxIndex>0)
	{
		last = hp->heapMaxIndex ;
		//exchange
		tmp = hp->arr[last];
		hp->arr[last] = hp->arr[0];
		hp->arr[0] = tmp;
		hp->heapMaxIndex -= 1;
		maxHeapify(hp,0);	//make heap from root node 0 to heapMaxIndex
	}
}

void printArr(int *p, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ",p[i]);
	}
}

int main()
{
	int a[]= {15,25,32,23,1,-4,35,2,-85,42,0,12,26,56,45,12,145,17,25,21};
	printArr(a,20);
	printf("\n");

	Heap hpa,*phpa;
	phpa =  createHeap(a,20,&hpa);
	heapSort(phpa);

	printArr(a,20);
	putchar('\n');
	return 0;
}