/*
	��ƽ��
	����һ����Ȼ��n, �������10�����1��������ƽ��ֵ
	���С�ڵ���10�� ���number is wrong
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