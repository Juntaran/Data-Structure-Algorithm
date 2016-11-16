#include<iostream>
using namespace std;

char** GrayCode(int n)
{
    int temp = 1;
    for(int i=0; i<n; i++)
        temp*=2;//n位格雷码一共有2^n个码字
    char **graycode = new char*[temp];//动态申请2^n *n大小的数组，存放格雷码
    for(int i=0; i<temp; i++)
    {
        graycode[i]=new char[n];//动态申请二维数组
    }
    if(n==1)
    {
        //递归终止条件
        graycode[0][0]='0';
        graycode[1][0]='1';
        return graycode;
    }
    char **p = GrayCode(n-1);//开始递归
    for(int i=0; i<temp/2; i++)
    {
        graycode[i][0]='0';
        graycode[i+temp/2][0]='1';
        for(int j=1; j<n; j++)
        {
            graycode[i][j]=p[i][j-1];
            graycode[temp-i-1][j]=p[i][j-1];//注意是顺序，上下对称
        }
    }
    return graycode;
}

int main()
{
    int x;
    cin>>x;
    int m = 1;
    for(int i=0; i<x; i++)
        m*=2;
    char** p = GrayCode(x);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<x; j++)
        {
            cout<<p[i][j];
        }
        cout<<endl;
    }
    return 0;
}