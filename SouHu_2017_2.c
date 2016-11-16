/*
	һ��������N��Ԫ�أ�ʹ��ð��Ԫ�ض�������������
	�����һ��Ϊ����Ԫ�ظ���n
	�ڶ�������n��Ԫ��
	
	���һ�У�������֮������
*/

#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintNums(int* nums, int length)
{
	printf("%d", nums[0]);
	for (int i = 1; i < length; ++i)
	{
		printf(" %d", nums[i]);
	}
	printf("\n");
}

void Bubble(int* nums, int length)
{
	int temp;
	for (int i = 0; i < length; ++i)
	{
		for (int j = i + 1; j < length; ++j)
		{
			if (nums[i] > nums[j])
			{
				swap(&nums[i], &nums[j]);
			}
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nums = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);
		
		if (n == 1)
		{
			printf("%d", nums[0]);
			continue;
		}
		Bubble(nums, n);
		PrintNums(nums, n);
	}
	return 0;
}