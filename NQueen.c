#include<stdio.h>
#include<math.h>

int place(int k,int *X)//检查可不可以放置一个新的皇后
{
    int i = 1;
    while( i < k )
    {
        if( (X[i]==X[k]) || (abs(X[i]-X[k])==abs(i-k)) )
		{
			return 0;
		}
        i++;
    }
    return 1;
}
void Nqueens(int n,int *X)
{
    int k = 1;
	int i;
    X[1] = 0;
    while( k > 0 )
    {
        X[k] = X[k]+1;
        while( (X[k]<=n) && (!place(k,X)) )
		{
			X[k] ++;
		}
        if( X[k] <=n )
		{
			if( k == n )
            {
                for( i=1; i<=n; i++ )
				{
					printf("%-6d",X[i]);
				}
                printf("\n");
            }
            else
            {
                k ++;
                X[k] = 0;
            }
		}
        else
		{
			k = k - 1;
		}			
    }
}
int main()
{
    int n;
    int i;
    printf("请输入皇后的个数:");
    scanf("%d",&n);
    int X[20];
    Nqueens(n,X);
}