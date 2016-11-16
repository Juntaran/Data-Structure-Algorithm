#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "malloc.h"

int prime(int y)
{
	int i;
	if(y==1) return 0;
	if(y==2) return 1;
	for(i=2; i<y; i++)
	{
		if(y%i==0)
			return 0;
	}
	return 1;
}

void printRet(int* ret, int size)
{
    int i;
    for( i=size-1; i>=0; i-- )
    {
        printf("%d ", ret[i]);
	}
}

int main()
{
	int a,i;
    int *ret = (int*)malloc(sizeof(int)*1024);
    int j = 0;
	scanf("%d",&a);
	for(i=a; i>1; i--)
	{
		if( a%i==0 && prime(i)==1 )
		{
			a=a/i;
			ret[j] = i;
			i++;
            j++;
		}
		else
			continue;
	}
	printRet(ret, j);
	return 0;
}