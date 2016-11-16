#include <stdio.h>
#include<stdlib.h>

int main()
{
	int a=22;
	char s[100];
	itoa(a,s,2);
	printf("%s\n",s);
	
	int len = 0;
	while( s[len] != NULL )
	{
		len ++;
	}
	printf("len is %d\n", len);
	int i;
	for( i=0; i<len/2; i++ )
	{
		char temp = s[i];
		printf("temp is %c\n", temp);
		s[i] = s[len-i-1];
		printf("s[%d] is %c\n", i, s[i]);
		s[len-i-1] = temp;
		printf("s[%d] is %c\n", len-i-1, s[len-i-1]);
	}
	
	printf("%s\n", s);
	
	return 0;
}