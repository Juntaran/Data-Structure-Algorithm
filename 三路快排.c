/*
http://blog.csdn.net/huhao_bupt/article/details/4446299
*/


#include <stdio.h>
#include <stdlib.h>

#define BIGNUM 1000
#define M 10

void swap(int *a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertsort(int a[],int n)
{
    int i ,j ;
    for(i=1; i<n; i++)
    {
        int temp = a[i];
        for(j=i; (j>=1)&&(temp<a[j-1]); j--)
        {
            a[j]=a[j-1];
        }
        a[j] = temp;
    }
}

void partition(int a[],int l,int r)
{

    int left = l,right = r;
    int i=l,j=r,m,v1=a[l],v2=a[r];

    if((r-l)<M)
    {
        return;
    }

    while(v1==v2)
    {
        v1= a[++l];
        if(l==r)
        {
            return;
        }
    }

    if(v1>v2)
    {
        swap(&v1,&v2);
    }


    while(a[i]<=v1)
    {
        i++;
    }

    m=i;

    while(a[j]>v2)
    {
        j--;
    }

    while(m<=j)
    {
        if(a[m]<=v1)
        {
            if(i!=m)
            {
                swap(&a[m],&a[i]);
            }
            i++;
            m++;
        }
        else if(a[m]>v2)
        {
            swap(&a[m],&a[j]);
            j--;
        }
        else
        {
            m++;
        }
    }

    partition(a,left,i-1);
    partition(a,i,m-1);
    partition(a,m,right);
}

void quicksort(int a[],int n)
{
    partition(a,0,n-1);
    insertsort(a,n);
}

void main()
{
    int i,a[BIGNUM];

    printf("**************Array before quicksort***************\n");

    for(i=0; i<BIGNUM; i++)
    {
        a[i] = rand()%BIGNUM;
        printf("%d ",a[i]);
    }

    printf("\n**************Array after quicksort***************\n");

    quicksort(a,BIGNUM);

    for(i=0; i<BIGNUM; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
}