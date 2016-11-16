#include <stdio.h>
#include <stdlib.h>

int com( const void *a, const void *b )
{
    return *(int*)a - *(int*)b;
}

int coinChange( int* coins, int coinsSize, int amount )
{
	//��������һ����amount+1һ���������Array����ʾ��0-amount����ȫ�������
    int *array = (int*)malloc(sizeof(int)*(amount+1));
	//����Ҫ��coins��С��������һ��	
    qsort( coins, coinsSize, sizeof(int), com );  
	//0��������ǲ���Ҫ���  ���Կ��Ը�Array[0] = 0��
    array[0] = 0;

    int i,j;
    int nVal;
	
	/*
		����ȫ��Array����, 
		i ���Ƕ�Ӧ��Ҫͨ��Ӳ����ϳ���������,
		Array[i]��Ӧ�ľ��Ǵ�Ҫ��Ӳ�ҵ���Сֵ��
	*/
	
    for( i=1; i<amount+1; i++ )
    {
		//�ȸ�ÿ�����渽�ӳ�ʼֵamount+1��
        array[i] = amount + 1;
        for( j=0; j<coinsSize && coins[j]<=i; j++ )
        {
			/*
				Ȼ���Ӧ�ı������е�coins���顣
				��coins[j] == i��ʱ����Array[i] = 1��
				���ʾ�����ֻҪһ��Ԫ����ɡ�
			*/
            if( coins[j] == i )
            {
                array[i] = 1;
                break;
            }
			
			/*
				��i��ȥ��ǰ��һ��Ԫ�أ��õ�һ����ֵnVal��
				�鿴һ��nVal���ֵ��֮ǰ��û����ɵ���С��
			*/
            nVal = i - coins[j];
			//-1��ʾ��ǰ��coins�е�Ԫ���޷���������
            if( array[nVal]!=-1 && array[nVal]+1<array[i] )
            {
                array[i] = array[nVal] + 1;
            }
        }
		/*
			����coins�е�ֵ
			���array[i]��ֵû�иı����ĳ�ֵ����amount+1�Ļ���
			��˵���޷���������
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