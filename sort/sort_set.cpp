/*************************************************************************
    > File Name: sort_set.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: Wed 27 Jul 2016 04:01:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MaxRandom 100000						// 随机数生成范围
#define LengthOfWaitSort 100000					// 随机数生成个数


/*******************************************************************/
// 验证输出
void printAfterSort(int* nums, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%4d",nums[i]);
    }
    printf("\n");
}
/*******************************************************************/


/*******************************************************************/
// 直接插入排序
void InsertSort(int* nums, int length)
{
    int insertNum;
    for (int i = 0; i < length; ++i)
    {
        insertNum = nums[i];    // 待插入的元素
        int j = i;
        while (j>0 && insertNum<nums[j-1])
        {
            nums[j] = nums[j-1];
            j --;
        }
        nums[j] = insertNum;
    }
    // 输出
    printf("Insert Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 二分插入排序
void BinaryInsertSort(int* nums, int length)
{
    int insertNum;
    int middle;
    for (int i = 0; i < length; ++i)
    {
        insertNum = nums[i];
        int left  = 0;                          // 已排序数组左边界
        int right = i - 1;                      // 已排序数组右边界
        while (left <= right)                   // 二分法寻找插入位置
        {
            middle = (left + right) / 2;
            if (insertNum > nums[middle])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        for (int j = i; j > left; --j)
        {
            nums[j] = nums[j-1];
        }
        nums[left] = insertNum;
    }
    // 输出
    printf("Binary Insert Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 希尔排序
void ShellSort(int* nums, int length)
{
    int insertNum;
    int gap = (length + 1) / 2;                 // 本次初始增量取了上界
    while (gap)
    {
        for (int i = gap; i < length; ++i)
        {
            insertNum = nums[i];                // 待插入排序
            int j = i;
            while (j>=gap && insertNum<nums[j-gap])
            {
                nums[j] = nums[j-gap];
                j -= gap;
            }
            nums[j] = insertNum;                // 插入
        }
        gap = gap / 2;                          // 缩小增量
    }
    // 输出
    printf("Shell Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 直接选择排序
void SelcetSort(int* nums, int length)
{
    int temp;
    for (int i = 0; i < length; ++i)
    {
        for (int j = i+1; j < length; ++j)
        {
            if (nums[j] < nums[i])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    // 输出
    printf("Selcet Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 堆排序

// 堆的建立或调整
void filterDown(int current, int last, int* nums)
{
    int child = 2 * current + 1;                // child为current的子女位置
    int temp  = nums[current];                  // 暂存子树根结点
    while (child <= last)                       // 判断是否到最后结尾
    {
        if (child<last && nums[child]<nums[child+1])
        {
            child ++;                           // 让child指向两个孩子中的最大的
        }
        if (temp >= nums[child])                // temp的关键码大则不作调整
        {
            break;
        }
        else                                    // 否则孩子中大者上移
        {
            nums[current] = nums[child];
            current = child;
            child = 2 * child + 1;
        }
    }
    nums[current] = temp;
}

// 排序
void HeapSort(int* nums, int length)
{
    for (int i = (length-2)/2; i >= 0; --i)
    {
        filterDown(i, length-1, nums);          // 建立堆
    }
    for (int i = length-1; i > 0; --i)
    {
        int temp = nums[i];
        nums[i] = nums[0];
        nums[0] = temp;
        filterDown(0, i-1, nums);               // 不断调整堆为最大堆
    }
    // 输出
    printf("Heap Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 冒泡排序
void BubbleSort(int* nums, int length)
{
    int temp;
    for (int i = 0; i < length; ++i)
    {
        for (int j = i+1; j < length; ++j)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    // 输出
    printf("Bubble Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 鸡尾酒排序(双向冒泡)
void ShakerSort(int* nums, int length)
{
    int left  = 0;
    int right = length - 1;
    int temp;
    int flag;                                   // 左右有序标志位

    while (left < right)
    {
        for (int i = left; i < right; ++i)      // 从左向右冒泡
        {
            if (nums[i] > nums[i+1])
            {
                temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                flag = i;
            }
        }
        right = flag;

        for (int j = right; j > left; --j)      // 从右向左冒泡
        {
            if (nums[j] < nums[j-1])
            {
                temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
                flag = j;
            }
        }
        left = flag;
    }
    // 输出
    printf("Shaker Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 快速排序 递归
void quick_sort(int* nums, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int flag = nums[left];

        while (i < j)
        {
            while (i<j && nums[j]>=flag)        // 从右向左找第一个比基数小的元素
            {
                j --;
            }
            if (i < j)
            {
                nums[i++] = nums[j];
            }

            while (i<j && nums[i]<=flag)        // 从左向右找第一个比基数大的元素
            {
                i ++;
            }
            if (i < j)
            {
                nums[j--] = nums[i];
            }
        }

        nums[i] = flag;
        quick_sort( nums, left, i-1 );
        quick_sort( nums, i+1, right);
    }
}

void QuickSort(int* nums, int length)
{
    int left  = 0;
    int right = length - 1;
    quick_sort(nums, left, right);
    // 输出
    printf("Quick Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 快速排序 非递归

int q_partition(int* nums, int low, int high)
{
	int flag = nums[low];						// 选第一个元素作为枢纽元
	
	while (low < high)
	{
		while (low<high && nums[high]>=flag)
			high --;
												// 从后向前找到第一个小于flag的元素，
												// 放到low位置
		nums[low] = nums[high];					
		
		while (low<high && nums[low]<=flag)
			low ++;
												// 从前向后找到第一个大于flag的元素，
												// 放到high位置
		nums[high] = nums[low];
	}
	nums[low] = flag;							// flag元素放到low的位置
	return low;
}

void QuickSort_Unrecursion(int* nums, int length)
{
	int q_stack[length*2];						// 递归层数设置
												// 栈中保存下次需要排序的子数组的
												// 开始位置和结束位置
	int top = -1;
	q_stack[++top] = 0;
	q_stack[++top] = length - 1;
	
	while (top > 0)								// 栈非空
	{
		int high = q_stack[top--];
		int low  = q_stack[top--];
		int middle = q_partition(nums, low, high);
		
		if (middle + 1 < high)					// 右边子数组入栈
		{
			q_stack[++top] = middle + 1;
			q_stack[++top] = high;
		}
		if (low < middle - 1)					// 左边子数组入栈
		{
			q_stack[++top] = low;
			q_stack[++top] = middle - 1;
		}
	}
	// 输出
    printf("Quick Sort Unrecursion:\n");
    printAfterSort(nums, length);
}

/*******************************************************************/


/*******************************************************************/
// 归并排序

// 合并数组
void merge(int* sourceArr, int* tempArr, int left, int middle, int right)
{
    int i = left;
	int j = middle + 1;
	int k = left;
	
	while (i!=middle+1 && j!=right+1)
	{
		if (sourceArr[i] >= sourceArr[j])
		{
			tempArr[k++] = sourceArr[j++];
		}
		else
		{
			tempArr[k++] = sourceArr[i++];
		}
	}
	while (i != middle+1)
	{
		tempArr[k++] = sourceArr[i++];
	}
	while (j != right+1)
	{
		tempArr[k++] = sourceArr[j++];
	}
	for (i = left; i <= right; ++i)
	{
		sourceArr[i] = tempArr[i];
	}
}
// 内部递归
void recursive(int* sourceArr, int* tempArr, int left, int right)
{
    int middle;
	if (left < right)
	{
		middle = (left + right) / 2;
		recursive(sourceArr, tempArr, left, middle);
		recursive(sourceArr, tempArr, middle+1, right);
		merge(sourceArr, tempArr, left, middle, right);
	}
}
// 函数入口
void MergeSort(int* nums, int length)
{
    int left  = 0;
    int right = length - 1;
	int* tempArr = (int*)malloc(sizeof(int)*length);
    recursive(nums, tempArr, left, right);
    // 输出
    printf("Merge Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 计数排序
void CountingSort(int* nums, int length)
{
    int* mark_array = (int*)malloc(sizeof(int)*MaxRandom);
    memset(mark_array, 0, MaxRandom*sizeof(int));

    for (int i = 0; i < length; ++i)
    {
        mark_array[nums[i]] ++;                 // 统计元素出现次数
    }
    int k = 0;
    for (int i = 0; i < MaxRandom; ++i)
    {
        if (mark_array[i] != 0)
        {
            for (int j=0; j < mark_array[i]; ++j)
            {
                nums[k++] = i;
            }
        }
    }
    // 输出
    printf("Counting Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// 基数排序
// 取一个数字从低到高第pos位的位数
int GetNumInPos(int num,int pos)
{
	int temp = 1;
	for (int i = 0; i < pos-1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}
// 取一个数字的位数
int GetDigt(int num)
{
	int n = 0;
	while (num > 0)
	{
		n ++;
		num /= 10;
	}
	return n;
}

void RadixSort(int* nums, int length)
{
	int digitRandom = GetDigt(MaxRandom);		// 得到最大随机数位数
    int* radixArray[10];						// 对应0-9序列
	for (int i = 0; i < 10; ++i)
	{
		radixArray[i] = (int*)malloc(sizeof(int)*(length+1));
		radixArray[i][0] = 0;					// index为0处记录这组数据个数
	}
	
	for (int pos = 1; pos <= digitRandom; ++pos)
	{				
	
		for (int i = 0; i < length; ++i)		// 分配过程
		{
			int num = GetNumInPos(nums[i], pos);
			int index = ++radixArray[num][0];
			radixArray[num][index] = nums[i];
		}
		
		for (int i = 0, j = 0; i < 10; ++i)		// 收集
		{
			for (int k = 1; k <= radixArray[i][0]; ++k)
			{
				nums[j++] = radixArray[i][k];
			}
			radixArray[i][0] = 0;				// 复位
		}
	}
    // 输出
    printf("Radix Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/



int main()
{
    clock_t start_time, finish_time;
    double duration;

    srand( (unsigned)time(NULL) );              // 生成随机数种子
    int length = LengthOfWaitSort;
    int nums[length];
    int temp[length];
    printf("Initial array:\n");
    for (int i = 0; i < length; ++i)            // 输出随机数组nums
    {
        nums[i] = rand()%(MaxRandom-1);         // MaxRandom-1以内生成20个随机数
        printf("%4d", nums[i]);
    }
    memcpy(temp, nums, length*sizeof(int));     // 用一个temp数组记录排序前的数组
    printf("\n\n");

    start_time = clock();
    InsertSort(nums, length);                   // 直接插入排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    BinaryInsertSort(nums, length);             // 二分插入排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    ShellSort(nums, length);                    // 希尔排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    SelcetSort(nums, length);                   // 直接选择排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    HeapSort(nums, length);                     // 堆排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    BubbleSort(nums, length);                   // 冒泡排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    ShakerSort(nums, length);                   // 鸡尾酒排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    QuickSort(nums, length);                    // 快速排序 递归
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组
	
	start_time = clock();
    QuickSort_Unrecursion(nums, length);        // 快速排序 非递归
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    MergeSort(nums, length);                    // 归并排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组

    start_time = clock();
    CountingSort(nums, length);                 // 计数排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组
	
	start_time = clock();
    RadixSort(nums, length);                 	// 基数排序
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // 复原nums数组


    return 0;
}