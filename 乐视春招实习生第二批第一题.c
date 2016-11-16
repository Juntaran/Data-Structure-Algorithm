#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"


int TwoToTen(char *s)
{
	int dec=0;
	while (*s !='\0')
		dec=(dec<<1) + *s++-'0';
	return dec;
}

char *itoa2(int num, char *str, int radix)   
{
    char string[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char* ptr = str;
    int denom = 0;  //ำเสý
    int count = -1;
    int i;
    int j;

    while (num >= radix)
    {
        denom   = num % radix;
        num    /= radix;
        *ptr++  = string[denom];
        count++;
    }

    if (num)
    {
        *ptr++ = string[num];
        count++;
    }

    *ptr = '\0';
    j    = count;

    for (i = 0; i < (count + 1) / 2; i++)
    {
        int temp = str[i];
        str[i]   = str[j];
        str[j--] = temp;
    }

    return str;
}

int reverseBit(int a)
{
	char s[100];
	itoa2(a,s,2);

	int len = 0;
	while( s[len] )
	{
		len ++;
	}
	int i;
	for( i=0; i<len/2; i++ )
	{
		char temp = s[i];
		s[i] = s[len-i-1];
		s[len-i-1] = temp;
	}


	int ret = TwoToTen(s);
	return ret;
}

int main()
{
	int N;
	while(scanf("%d",&N) != EOF)
	{
		int* s = (int*)malloc(sizeof(int)*N);
		int i;
		for( i=0; i<N; i++ )
		{
			scanf("%d", &s[i]);
		}
		for( i=0; i<N; i++ )
		{
			if( s[i]%2 == 0 )
			{
				s[i] = reverseBit(s[i]);
			}
		}
		for( i=0; i<N; i++ )
		{
			printf("%d ", s[i]);
		}
	}
	return 0;
}