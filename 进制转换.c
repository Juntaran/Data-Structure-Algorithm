#include<stdio.h>

void Print10To62(int num)
{
    int ret[1000];
    if (num == 0) 
		printf("0");
    int i = 0;
    while (num > 0)
    {
        int temp = num % 62;
        ret[i] = temp;
        num = num / 62;
        ++ i;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if (ret[j] >= 10 && ret[j] < 36) 
			printf("%c", ret[j]-10+'a');
		else if (ret[j] >= 36 && ret[j] < 62) 
			printf("%c", ret[j]-10+'A');
        else 
			printf("%d", ret[j]);
    }
}

int main()
{
	int x = 62;
	Print10To62(x);
	return 0;
}