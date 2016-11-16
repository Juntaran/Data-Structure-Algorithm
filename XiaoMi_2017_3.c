#include <stdio.h>

// 反转单词
void ReverseWord(char* left, char* right)
{
    if (left== NULL || right==NULL)
        return;
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        
        left ++;
        right --;
    }
}

void Reverse(char* str)
{
    if (str == NULL)
        return;
    
    char* left = str;
    char* right = str;
    while (*(right+1) != '\0')
        right++;
    
    // 先反转整个句子
    ReverseWord(left, right);
    
    // 再逐步反转每个单词
    left = str;
    right = str;
    while (*left != '\0')
    {
        if (*left == ' ')
        {
            left ++;
            right++;
        }
        else if (*right==' ' || *right=='\0')
        {
            ReverseWord(left, --right);
            left = ++right;
        }
        else
        {
            right ++;
        }
    }
}

int main()
{
	char str[100000];
	gets(str);
	printf("%d", sizeof(str));
	Reverse(str);
	printf("%s\n", str);
    return 0;
}