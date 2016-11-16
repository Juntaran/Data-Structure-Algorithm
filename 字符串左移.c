/*
String Shifting
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
���ǹ涨��һ���ַ�����shift�������£�
shift(��ABCD��, 0) = ��ABCD��
shift(��ABCD��, 1) = ��BCDA��
shift(��ABCD��, 2) = ��CDAB��
����֮, ���ǰ�������N���ַ���������, ���򸽼ӵ����Ҳࡣ
����һ������Ϊn���ַ��������ǹ涨�����Խ���n�������ѭ��shift������
���shift(string, x) = string (0 <= x < n), ���ǳ���Ϊһ��ƥ��(match)��
����shift�����г���ƥ��Ĵ�����
����
���������һ���������ַ�����ֻ������Сд�ַ���
���
���������һ�У��������ƥ�������

��������
byebyebye
�������
3

Hint
���ݷ�Χ
����40%�����ݣ��ַ������Ȳ�����100��
����100%�����ݣ��ַ������Ȳ�����10^6��
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
    // n���ܴ���length
    n = n % length;

    // ��һ����
    char* FirstStart = str;
    char* FirstEnd   = str + n - 1;

    // �ڶ�����
    char* SecondStart = str + n;
    char* SecondEnd   = str + length - 1;

    // �ȷ�ת��һ����
    ReverseWord(FirstStart, FirstEnd);
    printf("%s\n", str);
    // �ٷ�ת�ڶ�����
    ReverseWord(SecondStart, SecondEnd);
    printf("%s\n", str);
    printf("%s\n", SecondEnd);
    // �����ٷ�ת
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