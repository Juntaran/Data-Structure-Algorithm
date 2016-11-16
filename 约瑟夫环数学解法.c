#include <stdio.h>

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
    if ( n<1 || m<1 )
        return -1;
    if ( n == 1 )
		return 0;
	else
		return (LastRemaining_Solution(n-1,m)+m)%n;
}

int main()
{
	unsigned int i = -4;
	unsigned int j = 3;
	printf("%d\n", i%j);
	int ret = LastRemaining_Solution( 7, 3 );
	printf("%d\n", ret);
}