#include<stdio.h>
#include<stdlib.h>


//�Ե����Ϲ������ѣ�Ȼ��ÿ�α������ѵĸ��ڵ㣬������ɶ�����

int array[11]= {0,1,3,2,5,4,7,6,8,10,9};
int heapnum = 10;

//������
void MAX(int i)
{
/*
	������������Ϊ�¼�Ԫ�ص��ӽڵ�ʱ��
	���¹��ɵĶ��ٴ�Build������
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
	�����n��Ԫ�ع�����ʱ����n/2���޸�Ҷ�ڵ㣻
	����ЩҶ�ڵ�Ϊ��������������������ѣ�
	���i��ȡֵ��Χ��n/2���޵�1��
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
	���ѶѶ���Ԫ��������������Ԫ�أ�ÿ������ʱ���Ѷ�Ԫ�������һ��Ԫ�ؽ�����
	Ȼ��������Ԫ����Ŀ��1��Ȼ�����γɵĶ����¹��������ѡ�
	������ÿ��ѭ���󣬶ѵĵ�һ���������������������ݣ�Ȼ����������������һλ��
	����ѭ�������γ������������顣
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