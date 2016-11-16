#include <stdio.h>

char strnum1[210], strnum2[210];
int num1[210], num2[210], ans[40000];

int main()
{
    gets(strnum1);
    gets(strnum2);
    int m = 0, n = 0;

    //将字符串转化为数字
    while (strnum1[m])
    {
        num1[m] = strnum1[m] - '0';
        m++;
    }
    while (strnum2[n])
    {
        num2[n] = strnum2[n] - '0';
        n++;
    }
    int up; //进位
    int tmp ; //临时变量
    int k, p, i, j; // k,p 记录计算的位置
    for (i = m - 1, k = 0; i >= 0; i--, k++)
    {
        tmp = 0, up = 0;
        for (j = n - 1, p = 0; j >= 0; j--, p++)
        {
            tmp = num1[i] * num2[j] + up + ans[k + p];
            ans[k + p] = tmp % 10;
            up = tmp / 10;
        }
        if (up > 0)
            ans[k + p] = up;
    }
    int len = m * n;
    while (ans[len--] == 0);
    //逆序输出
    for (int i = len + 1; i >= 0; i--)
        printf("%d", ans[i]);
    return 0;
}