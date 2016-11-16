#include<stdio.h>
#include<stdlib.h>


//自底向上构建最大堆，然后每次保存最大堆的根节点，即可完成堆排序

int array[11]= {0,1,3,2,5,4,7,6,8,10,9};
int heapnum = 10;

//堆排序
void MAX(int i)
{
/*
	在两个最大堆作为新加元素的子节点时，
	把新构成的堆再次Build成最大堆
*/
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;
	int mid;
	if(left <= heapnum)
		if(array[left] > array[i])
		{
			largest = left;
		}
	if(right <= heapnum)
		if(array[right] > array[largest])
		{
			largest = right;
		}
	if(largest != i)
	{
		mid = array[i];
		array[i] = array[largest];
		array[largest] = mid;
		MAX(largest);
	}
}
void BUILD(void)
{
/*
	如果有n个元素构建堆时，有n/2上限个叶节点；
	依这些叶节点为基础建立整个数组的最大堆，
	因此i的取值范围是n/2下限到1。
*/
	int i = heapnum/2;
	for(i=heapnum/2; i>=1; i--)
	{
		MAX(i);
	}
}


void SORT(void)          
{
/*
	最大堆堆顶的元素是数组中最大的元素，每次排序时将堆顶元素与最后一个元素交换，
	然后将最大堆中元素数目减1，然后将新形成的堆重新构建成最大堆。
	这样，每次循环后，堆的第一个数都是数组中最大的数据，然后把其放在数组的最后一位。
	依次循环即可形成升序排列数组。
*/
	int i;
	int mid;
	for(i=10; i>=2; i--)
	{
		mid = array[1];
		array[1] = array[i];
		array[i] = mid;
		heapnum--;
		MAX(1);
	}
}
void OUT(void)
{
	int i=1;

	for(i=1; i<=10; i++)
		printf("%d\n",array[i]);
}
void main()
{
	BUILD();
	SORT();
	OUT();
	system("pause");
	return 0;
}