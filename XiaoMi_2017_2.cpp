/*
	树的高度
	时间限制：C/C++语言 1000MS；其他语言 3000MS
	内存限制：C/C++语言 65536KB；其他语言 589824KB
	题目描述：
	现在有一棵合法的二叉树，树的节点都是用数字表示，
	现在给定这棵树上所有的父子关系，求这棵树的高度
	
	输入
		输入的第一行表示节点的个数n（1<=n<=1000，节点的编号为0到n-1）组成，
	下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
	
	输出
		输出树的高度，为一个整数
		
	样例输入
	5
	0 1
	0 2
	1 3
	1 4
	样例输出
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

// 二分查找
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