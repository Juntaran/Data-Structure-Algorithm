#include<stdio.h>

void shift(int a[] , int i , int m)
{
	int k , t;

	t = a[i];
	k = 2 * i + 1;
	while (k < m)
	{
		if ((k < m - 1) && (a[k] < a[k+1])) k ++;
		if (t < a[k])
		{
			a[i] = a[k];
			i = k;
			k = 2 * i + 1;
		}
		else break;
	}
	a[i] = t;
}

void heap(int a[] , int n)  //a 为排序数组，n为数组大小（编号0-n-1）
{
	int i , k;

	for (i = n/2-1; i >= 0; i --) 
		shift(a , i , n);
	for (i = n-1; i >= 1; i --)
	{
		k = a[0];
		a[0] = a[i];
		a[i] = k;
		shift(a , 0 , i);
	}

}
int main()
{
	int a[10],i;
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);
	heap(a,10);
	for(i=0; i<10; i++)
		printf("%d",a[i]);
	return 0;
}