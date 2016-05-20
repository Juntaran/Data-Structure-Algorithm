// 百度面试题
//数组中除两个数字外，其它数字都出现了2次。要求尽可能快的找出这两个数字
//By MoreWindows (http://blog.csdn.net/MoreWindows)
#include <stdio.h>

void FindTwoNotRepeatNumberInArray(int *a, int n, int *pN1, int *pN2)
{
	int i, j, temp;
    
	//计算这两个数的异或结果
	temp = 0;
	for (i = 0; i < n; i++)
		temp ^= a[i];
	
	// 找第一个为1的位
	for (j = 0; j < sizeof(int) * 8; j++)
		if (((temp >> j) & 1) == 1)
			break;

	// 第j位为1,说明这两个数字在第j位上是不相同的
	// 由此分组即可
	*pN1 = 0, *pN2 = 0;
	for (i = 0; i < n; i++)
		if (((a[i] >> j) & 1) == 0)
			*pN1 ^= a[i];
		else
			*pN2 ^= a[i];
}
void PrintfArray(int a[], int n)
{
	int i;
	for ( i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void FindTwoNotRepeatNumberInArray2(int *a, int n, int &one, int& two)
{
	int i,j,tmp;
	tmp = 0;
	for (i = 0; i < n; ++i)
	{
		tmp ^= a[i];
	}

	int mytemplate = tmp & (~tmp + 1);
	one = 0;
	two = 0;
	for (i = 0; i < n; ++i)
	{
		if ((a[i] & mytemplate) == 0)
		{
			one ^= a[i];
		} 
		else
		{
			two ^= a[i];
		}
	}
}

int main()
{
	printf("    白话经典算法系列之十二数组中不重复的个数字(百度面试题) \n");      
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n"); 

	const int MAXN = 10;
	//int a[MAXN] = {1, 2, 7, 5, 100,  100, 6, 1, 2, 5};
	int a[MAXN] = {1, 2, 3, 4, 1,  2, 3, 4, 0, 5};

	printf("数组为: \n");
	PrintfArray(a, MAXN);

	int nNotRepeatNumber1, nNotRepeatNumber2;
	FindTwoNotRepeatNumberInArray(a, MAXN, &nNotRepeatNumber1, &nNotRepeatNumber2);
	printf("两个不重复的数字分别为: %d %d\n", nNotRepeatNumber1, nNotRepeatNumber2);
	return 0;
}