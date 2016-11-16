#include<stdio.h>
#include<cstring>

using namespace std;

/*
n个谷仓环状连在一起，只有相邻两个之间可以铺一条路。
给出p个要求，每个要求x,y表示x和y想联系。
当然，因为环形，可以双向铺路。求最少铺多少路。

*/

struct arr
{
	long x,y;
} a[10001];

char f[2001];

long start,end,temp1,temp2,i,j,k,min,n,p,temp;

inline long c(long x)
{
	if (x < start) 
		return x+n;
	if (x > end) 
		return x-n;
	return x;
}

int main()
{
	scanf("%ld %ld",&n,&p);
	for (i = 1; i <= p; i ++)
	{
		scanf("%ld %ld",&a[i].x, &a[i].y);
		if (a[i].x>a[i].y)
		{
			temp = a[i].x;
			a[i].x = a[i].y;
			a[i].y = temp;
		}
	}
	long ans=n;
	for (i = 1; i <= n; i ++)
	{
		start = i;
		end = start+n-1;
		min = 0;
		memset(f,0,sizeof(f));
		for (j = 1; j <= p; j ++)
		{
			temp1 = c(a[j].x);
			temp2 = c(a[j].y);
			if (temp1> temp2)
			{
				temp  = temp1;
				temp1 = temp2;
				temp2 = temp;
			}
			for (k = temp1; k < temp2; k ++) 
				f[k]=1;
		}
		for (j = start; j <= end; j ++) 
			if (f[j] == 1) 
				min++;
		if (min < ans) 
			ans=min;
	}
	printf("%ld", ans);
	return 0;
}