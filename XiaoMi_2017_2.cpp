/*
	���ĸ߶�
	ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
	�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
	��Ŀ������
	������һ�úϷ��Ķ����������Ľڵ㶼�������ֱ�ʾ��
	���ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
	
	����
		����ĵ�һ�б�ʾ�ڵ�ĸ���n��1<=n<=1000���ڵ�ı��Ϊ0��n-1����ɣ�
	������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��
	
	���
		������ĸ߶ȣ�Ϊһ������
		
	��������
	5
	0 1
	0 2
	1 3
	1 4
	�������
	3
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <bits/stdc++.h>

using namespace std;

void SortTwoArray(int* parent, int* node, int length)
{
	int temp1;
	int temp2;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i; ++j)
		{
			if (node[j] > node[j+1])
			{
				temp1 = node[j+1];
				node[j+1] = node[j];
				node[j] = temp1;
				
				temp2 = parent[j+1];
				parent[j+1] = parent[j];
				parent[j] = temp2;
			}
		}
	}
}

// ���ֲ���
int Binary_Search(int* nums, int length, int key)
{
    int left, right, middle;
    left  = 0;
    right = length - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (key < nums[middle])
        {
            right = middle - 1;
        }
        else if (key > nums[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
	return -1;
}


int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 1)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("1\n");
			continue;
		}
		int length = n - 1;
		int* parent = (int*)malloc(sizeof(int)*length);
		int* node = (int*)malloc(sizeof(int)*length);
		for (int i = 0; i < length; ++i)
		{
			scanf("%d", &parent[i]);
			scanf("%d", &node[i]);
		}
		SortTwoArray(parent, node, length);
		int height = 1;
		int Num = node[length - 1];
		while (Num != 0)
		{
			int pos = Binary_Search(node, length, Num);
			Num = parent[pos];
			height ++;
		}
		printf("%d\n", height);
		free(parent);
        free(node);
	}
	return 0;
}