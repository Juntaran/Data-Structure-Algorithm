// �ٶ�������
//�����г����������⣬�������ֶ�������2�Ρ�Ҫ�󾡿��ܿ���ҳ�����������
//By MoreWindows (http://blog.csdn.net/MoreWindows)
#include <stdio.h>

void FindTwoNotRepeatNumberInArray(int *a, int n, int *pN1, int *pN2)
{
	int i, j, temp;
    
	//�������������������
	temp = 0;
	for (i = 0; i < n; i++)
		temp ^= a[i];
	
	// �ҵ�һ��Ϊ1��λ
	for (j = 0; j < sizeof(int) * 8; j++)
		if (((temp >> j) & 1) == 1)
			break;

	// ��jλΪ1,˵�������������ڵ�jλ���ǲ���ͬ��
	// �ɴ˷��鼴��
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
	printf("    �׻������㷨ϵ��֮ʮ�������в��ظ��ĸ�����(�ٶ�������) \n");      
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n"); 

	const int MAXN = 10;
	//int a[MAXN] = {1, 2, 7, 5, 100,  100, 6, 1, 2, 5};
	int a[MAXN] = {1, 2, 3, 4, 1,  2, 3, 4, 0, 5};

	printf("����Ϊ: \n");
	PrintfArray(a, MAXN);

	int nNotRepeatNumber1, nNotRepeatNumber2;
	FindTwoNotRepeatNumberInArray(a, MAXN, &nNotRepeatNumber1, &nNotRepeatNumber2);
	printf("�������ظ������ֱַ�Ϊ: %d %d\n", nNotRepeatNumber1, nNotRepeatNumber2);
	return 0;
}