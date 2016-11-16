/*
http://blog.csdn.net/huhao_bupt/article/details/4446299
*/


#include <stdio.h>
#include <stdlib.h>

#define BIGNUM 1000

void swap(int *a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

partion(int a[],int l,int r)
{
    int i=l,j=r,m;

    while(a[i]==0)
    {
        i++;
    }

    m=i;

    while(a[j]==2)
    {
        j--;
    }

    while(m<=j)
    {
        if(a[m]==0)
        {
            if(i!=m)
            {
                swap(&a[m],&a[i]);
            }
            i++;
            m++;
        }
        if(a[m]==1)
        {
            m++;
        }
        if(a[m]==2)
        {
            swap(&a[m],&a[j]);
            j--;
        }
    }
}

void main()
{
    int i,a[BIGNUM];

    printf("**************Array before partition***************\n");

    for(i=0; i<BIGNUM; i++)
    {
        a[i] = rand()%3;
        printf("%d ",a[i]);
    }

    printf("\n**************Array after partition***************\n");

    partion(a,0,BIGNUM-1);

    for(i=0; i<BIGNUM; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
}