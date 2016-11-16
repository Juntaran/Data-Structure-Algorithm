#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//O(N)的时间复杂度
int max_unique_substring3(char * str) 
{
    int maxlen = 0;
    int begin = 0;
    int n = strlen(str);
    int * next = (int*)malloc(sizeof(int)*n); //next[i]记录了下一个与str[i]重复的字符的位置
    int * first = (int*)malloc(sizeof(int)*(n+1)); //first[i]记录str[i]后面最近的一个重复点
    int hash[256];
    memset(hash,n,sizeof(hash));

    first[n] = n;
    for(int i=n-1; i>=0; i--)
    {
        next[i] = hash[str[i]];
		printf("next[%d] is %d\n", i, next[i]);
        hash[str[i]] = i;
        if (next[i] < first[i+1])
            first[i] = next[i];
        else
            first[i] = first[i+1]; //生成first[]表，复杂度是O(N)的
    }
    for(int i=0; i<n; i++)
    {
        if (first[i]-i > maxlen)
        {
            maxlen = first[i]-i;
            begin = i;
        }
    }
    free(first);
    free(next);
    printf("%s\n",  &str[begin]);
    return maxlen;
}

int main()
{
	char str[] = "axbdebpqawuva";
	int ret = max_unique_substring3(str);
	printf("%d\n", ret);
}