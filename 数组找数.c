// ���׻������㷨ϵ��֮ʮ�塿��һ��ǧ�֮��������
//  by MoreWindows( http://blog.csdn.net/MoreWindows )
//  ��ӭ��עhttp://weibo.com/morewindows
#include <stdio.h>
#include <math.h>
void PrintfArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}
int FindNumberInArray(int arr[], int n , int find_number)
{
    int next_arrive_index = abs(find_number - arr[0]);
    while (next_arrive_index < n)
    {
        if (arr[next_arrive_index] == find_number)
            return next_arrive_index;
        next_arrive_index += abs(find_number - arr[next_arrive_index]);
    }
    return -1;
}
int main()
{
    const int MAXN = 10;
    int arr[MAXN] = {4,5,6,5,6,7,8,9,10,9};
    PrintfArray(arr, MAXN);
    for (int i = 0; i < MAXN; i++)
        printf("����%d   \t�±�Ϊ%d\n", arr[i], FindNumberInArray(arr, MAXN, arr[i]));

    printf("����%d   \t�±�Ϊ%d\n", -1, FindNumberInArray(arr, MAXN, -1));
    printf("����%d   \t�±�Ϊ%d\n", 0, FindNumberInArray(arr, MAXN, 0));
    printf("����%d   \t�±�Ϊ%d\n", 100, FindNumberInArray(arr, MAXN, 100));
    return 0;
}