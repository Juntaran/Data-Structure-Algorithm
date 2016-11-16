#include <stdio.h>
#include<stdlib.h>

int bin_dec(char *p)
{
    int dec=0;
    while (*p !='\0')
        dec=(dec<<1) + *p++-'0';
    return dec;
}

int main()
{
	char s[] = "110";
	int ret = bin_dec(s);
	printf ("%d\n", ret);
}