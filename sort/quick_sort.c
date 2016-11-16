/*************************************************************************
	> File Name: quick_sort.c
	> Author: Juntaran
	> Mail: Jacinthmail@gmail.com
	> Created Time: Tue 10 May 2016 03:15:05 PM CST
 ************************************************************************/

#include <stdio.h>

void quick_sort( int* nums, int left, int right )
{
    if( left < right )
    {
        int i = left;
        int j = right;
        int flag = nums[left];
        
        while( i < j )
        {
            while( i<j && nums[j]>=flag )	// 从右向左找第一个小于x的数  
            {
                j--;
            }
            if( i < j )
            {
                nums[i++] = nums[j];
            }
        
            while( i<j && nums[i]<flag )	// 从左向右找第一个大于等于x的数
            {
                i++;
            }
			if( i < j )
            {
                nums[j--] = nums[i];
            }
        }  
		nums[i] = flag;
		quick_sort( nums, left, i-1 );
		quick_sort( nums, i+1, right);
    }
}

void printfNums( int* nums, int numsSize )
{
	int i;
	printf("\n");
	for( i=0; i<numsSize; i++ )
	{
		printf("%d ", nums[i]);
	}
}

int main()
{
	int nums[] = {9,8,7,6,5,4,3,2,1};
	int numsSize = 9;
	int left = 0;
	int right = 8;
	
	printfNums( nums, numsSize );
	quick_sort( nums, left, right );
	printfNums( nums, numsSize );
	
	return 0;
	
}