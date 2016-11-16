/*
	求平方
	读入一个自然数n, 如果大于10输出从1到该数的平方值
	如果小于等于10， 输出number is wrong
*/

#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 10)
		{
			printf("number is wrong\n");
			continue;
		}
		
		else
		{
			int i = 1;
			while (i <= n)
			{
				printf("%d %lld\n", i, i*i);
				++ i;
			}
		}
	}
	
	return 0;
}