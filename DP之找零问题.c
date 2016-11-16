#include <stdio.h>
#include <stdlib.h>

int com( const void *a, const void *b )
{
    return *(int*)a - *(int*)b;
}

int coinChange( int* coins, int coinsSize, int amount )
{
	//首先申请一个和amount+1一样大的数组Array，表示从0-amount遍历全部情况。
    int *array = (int*)malloc(sizeof(int)*(amount+1));
	//这里要给coins从小到大排序一下	
    qsort( coins, coinsSize, sizeof(int), com );  
	//0的情况就是不需要组合  所以可以给Array[0] = 0。
    array[0] = 0;

    int i,j;
    int nVal;
	
	/*
		遍历全部Array数组, 
		i 就是对应的要通过硬币组合出来的数字,
		Array[i]对应的就是存要的硬币的最小值。
	*/
	
    for( i=1; i<amount+1; i++ )
    {
		//先给每个里面附加初始值amount+1。
        array[i] = amount + 1;
        for( j=0; j<coinsSize && coins[j]<=i; j++ )
        {
			/*
				然后对应的遍历所有的coins数组。
				当coins[j] == i的时候则Array[i] = 1。
				这表示这个数只要一个元素组成。
			*/
            if( coins[j] == i )
            {
                array[i] = 1;
                break;
            }
			
			/*
				当i减去当前的一个元素，得到一个新值nVal，
				查看一下nVal这个值在之前有没有组成的最小数
			*/
            nVal = i - coins[j];
			//-1表示当前的coins中的元素无法组成这个数
            if( array[nVal]!=-1 && array[nVal]+1<array[i] )
            {
                array[i] = array[nVal] + 1;
            }
        }
		/*
			遍历coins中的值
			如果array[i]的值没有改变它的初值，即amount+1的话，
			就说明无法组成这个数
		*/
        if( array[i] == amount + 1 )
        {
            array[i] = -1;
        }
    }
	for( i=0; i<amount+1; i++ )
	{
		printf("%d ", array[i]);
	}
	printf("\n");
    return array[amount];
}

int main()
{
	int coins[] = {1,2,5};
	int coinsSize = 3;
	int amount = 11;
	
	int ret = coinChange( coins, coinsSize, amount );
	printf("ret is %d\n", ret);
	
	
}