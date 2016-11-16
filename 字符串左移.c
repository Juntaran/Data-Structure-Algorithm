/*
String Shifting
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
我们规定对一个字符串的shift操作如下：
shift(“ABCD”, 0) = “ABCD”
shift(“ABCD”, 1) = “BCDA”
shift(“ABCD”, 2) = “CDAB”
换言之, 我们把最左侧的N个字符剪切下来, 按序附加到了右侧。
给定一个长度为n的字符串，我们规定最多可以进行n次向左的循环shift操作。
如果shift(string, x) = string (0 <= x < n), 我们称其为一次匹配(match)。
求在shift过程中出现匹配的次数。
输入
输入仅包括一个给定的字符串，只包含大小写字符。
输出
输出仅包括一行，即所求的匹配次数。

样例输入
byebyebye
样例输出
3

Hint
数据范围
对于40%的数据，字符串长度不超过100；
对于100%的数据，字符串长度不超过10^6。
*/

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void ReverseWord(char* left, char* right)
{
    if (left==NULL || right==NULL)
        return;
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left  ++;
        right --;
    }
}

void ShiftWord(char* str, int n)
{
    if (str==NULL || n<=0)
        return;

    int length = strlen(str);
    // n可能大于length
    n = n % length;

    // 第一部分
    char* FirstStart = str;
    char* FirstEnd   = str + n - 1;

    // 第二部分
    char* SecondStart = str + n;
    char* SecondEnd   = str + length - 1;

    // 先反转第一部分
    ReverseWord(FirstStart, FirstEnd);
    printf("%s\n", str);
    // 再反转第二部分
    ReverseWord(SecondStart, SecondEnd);
    printf("%s\n", str);
    printf("%s\n", SecondEnd);
    // 整体再反转
    ReverseWord(FirstStart, SecondEnd);
    printf("%s\n", str);
}

int main()
{
    char str[1000000];
    char temp[1000000];
    while (cin >> str)
    {
        printf("str is %s\n", str);
        int length = strlen(str);
        printf("length is %d\n", length);
        int n = 1;
        strcpy(temp, str);
        printf("temp is %s\n", temp);
        int count = 0;
        while (n <= length)
        {
            ShiftWord(temp, 1);
            if (strcmp(str, temp) == 0)
                count ++;
            n ++;
        }
        printf("count is %d\n", count);
    }
    return 0;
}