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

#define MaxRandom 100000						// ��������ɷ�Χ
#define LengthOfWaitSort 100000					// ��������ɸ���


/*******************************************************************/
// ��֤���
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
// ֱ�Ӳ�������
void InsertSort(int* nums, int length)
{
    int insertNum;
    for (int i = 0; i < length; ++i)
    {
        insertNum = nums[i];    // �������Ԫ��
        int j = i;
        while (j>0 && insertNum<nums[j-1])
        {
            nums[j] = nums[j-1];
            j --;
        }
        nums[j] = insertNum;
    }
    // ���
    printf("Insert Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ���ֲ�������
void BinaryInsertSort(int* nums, int length)
{
    int insertNum;
    int middle;
    for (int i = 0; i < length; ++i)
    {
        insertNum = nums[i];
        int left  = 0;                          // ������������߽�
        int right = i - 1;                      // �����������ұ߽�
        while (left <= right)                   // ���ַ�Ѱ�Ҳ���λ��
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
    // ���
    printf("Binary Insert Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ϣ������
void ShellSort(int* nums, int length)
{
    int insertNum;
    int gap = (length + 1) / 2;                 // ���γ�ʼ����ȡ���Ͻ�
    while (gap)
    {
        for (int i = gap; i < length; ++i)
        {
            insertNum = nums[i];                // ����������
            int j = i;
            while (j>=gap && insertNum<nums[j-gap])
            {
                nums[j] = nums[j-gap];
                j -= gap;
            }
            nums[j] = insertNum;                // ����
        }
        gap = gap / 2;                          // ��С����
    }
    // ���
    printf("Shell Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ֱ��ѡ������
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
    // ���
    printf("Selcet Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ������

// �ѵĽ��������
void filterDown(int current, int last, int* nums)
{
    int child = 2 * current + 1;                // childΪcurrent����Ůλ��
    int temp  = nums[current];                  // �ݴ����������
    while (child <= last)                       // �ж��Ƿ�����β
    {
        if (child<last && nums[child]<nums[child+1])
        {
            child ++;                           // ��childָ�����������е�����
        }
        if (temp >= nums[child])                // temp�Ĺؼ������������
        {
            break;
        }
        else                                    // �������д�������
        {
            nums[current] = nums[child];
            current = child;
            child = 2 * child + 1;
        }
    }
    nums[current] = temp;
}

// ����
void HeapSort(int* nums, int length)
{
    for (int i = (length-2)/2; i >= 0; --i)
    {
        filterDown(i, length-1, nums);          // ������
    }
    for (int i = length-1; i > 0; --i)
    {
        int temp = nums[i];
        nums[i] = nums[0];
        nums[0] = temp;
        filterDown(0, i-1, nums);               // ���ϵ�����Ϊ����
    }
    // ���
    printf("Heap Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ð������
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
    // ���
    printf("Bubble Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ��β������(˫��ð��)
void ShakerSort(int* nums, int length)
{
    int left  = 0;
    int right = length - 1;
    int temp;
    int flag;                                   // ���������־λ

    while (left < right)
    {
        for (int i = left; i < right; ++i)      // ��������ð��
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

        for (int j = right; j > left; --j)      // ��������ð��
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
    // ���
    printf("Shaker Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// �������� �ݹ�
void quick_sort(int* nums, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int flag = nums[left];

        while (i < j)
        {
            while (i<j && nums[j]>=flag)        // ���������ҵ�һ���Ȼ���С��Ԫ��
            {
                j --;
            }
            if (i < j)
            {
                nums[i++] = nums[j];
            }

            while (i<j && nums[i]<=flag)        // ���������ҵ�һ���Ȼ������Ԫ��
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
    // ���
    printf("Quick Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// �������� �ǵݹ�

int q_partition(int* nums, int low, int high)
{
	int flag = nums[low];						// ѡ��һ��Ԫ����Ϊ��ŦԪ
	
	while (low < high)
	{
		while (low<high && nums[high]>=flag)
			high --;
												// �Ӻ���ǰ�ҵ���һ��С��flag��Ԫ�أ�
												// �ŵ�lowλ��
		nums[low] = nums[high];					
		
		while (low<high && nums[low]<=flag)
			low ++;
												// ��ǰ����ҵ���һ������flag��Ԫ�أ�
												// �ŵ�highλ��
		nums[high] = nums[low];
	}
	nums[low] = flag;							// flagԪ�طŵ�low��λ��
	return low;
}

void QuickSort_Unrecursion(int* nums, int length)
{
	int q_stack[length*2];						// �ݹ��������
												// ջ�б����´���Ҫ������������
												// ��ʼλ�úͽ���λ��
	int top = -1;
	q_stack[++top] = 0;
	q_stack[++top] = length - 1;
	
	while (top > 0)								// ջ�ǿ�
	{
		int high = q_stack[top--];
		int low  = q_stack[top--];
		int middle = q_partition(nums, low, high);
		
		if (middle + 1 < high)					// �ұ���������ջ
		{
			q_stack[++top] = middle + 1;
			q_stack[++top] = high;
		}
		if (low < middle - 1)					// �����������ջ
		{
			q_stack[++top] = low;
			q_stack[++top] = middle - 1;
		}
	}
	// ���
    printf("Quick Sort Unrecursion:\n");
    printAfterSort(nums, length);
}

/*******************************************************************/


/*******************************************************************/
// �鲢����

// �ϲ�����
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
// �ڲ��ݹ�
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
// �������
void MergeSort(int* nums, int length)
{
    int left  = 0;
    int right = length - 1;
	int* tempArr = (int*)malloc(sizeof(int)*length);
    recursive(nums, tempArr, left, right);
    // ���
    printf("Merge Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ��������
void CountingSort(int* nums, int length)
{
    int* mark_array = (int*)malloc(sizeof(int)*MaxRandom);
    memset(mark_array, 0, MaxRandom*sizeof(int));

    for (int i = 0; i < length; ++i)
    {
        mark_array[nums[i]] ++;                 // ͳ��Ԫ�س��ִ���
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
    // ���
    printf("Counting Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/


/*******************************************************************/
// ��������
// ȡһ�����ִӵ͵��ߵ�posλ��λ��
int GetNumInPos(int num,int pos)
{
	int temp = 1;
	for (int i = 0; i < pos-1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}
// ȡһ�����ֵ�λ��
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
	int digitRandom = GetDigt(MaxRandom);		// �õ���������λ��
    int* radixArray[10];						// ��Ӧ0-9����
	for (int i = 0; i < 10; ++i)
	{
		radixArray[i] = (int*)malloc(sizeof(int)*(length+1));
		radixArray[i][0] = 0;					// indexΪ0����¼�������ݸ���
	}
	
	for (int pos = 1; pos <= digitRandom; ++pos)
	{				
	
		for (int i = 0; i < length; ++i)		// �������
		{
			int num = GetNumInPos(nums[i], pos);
			int index = ++radixArray[num][0];
			radixArray[num][index] = nums[i];
		}
		
		for (int i = 0, j = 0; i < 10; ++i)		// �ռ�
		{
			for (int k = 1; k <= radixArray[i][0]; ++k)
			{
				nums[j++] = radixArray[i][k];
			}
			radixArray[i][0] = 0;				// ��λ
		}
	}
    // ���
    printf("Radix Sort:\n");
    printAfterSort(nums, length);
}
/*******************************************************************/



int main()
{
    clock_t start_time, finish_time;
    double duration;

    srand( (unsigned)time(NULL) );              // �������������
    int length = LengthOfWaitSort;
    int nums[length];
    int temp[length];
    printf("Initial array:\n");
    for (int i = 0; i < length; ++i)            // ����������nums
    {
        nums[i] = rand()%(MaxRandom-1);         // MaxRandom-1��������20�������
        printf("%4d", nums[i]);
    }
    memcpy(temp, nums, length*sizeof(int));     // ��һ��temp�����¼����ǰ������
    printf("\n\n");

    start_time = clock();
    InsertSort(nums, length);                   // ֱ�Ӳ�������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    BinaryInsertSort(nums, length);             // ���ֲ�������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    ShellSort(nums, length);                    // ϣ������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    SelcetSort(nums, length);                   // ֱ��ѡ������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    HeapSort(nums, length);                     // ������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    BubbleSort(nums, length);                   // ð������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    ShakerSort(nums, length);                   // ��β������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    QuickSort(nums, length);                    // �������� �ݹ�
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����
	
	start_time = clock();
    QuickSort_Unrecursion(nums, length);        // �������� �ǵݹ�
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    MergeSort(nums, length);                    // �鲢����
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����

    start_time = clock();
    CountingSort(nums, length);                 // ��������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����
	
	start_time = clock();
    RadixSort(nums, length);                 	// ��������
    finish_time = clock();
    duration = (double)(finish_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf( "%f ms\n\n", duration );
    memcpy(nums, temp, length*sizeof(int));     // ��ԭnums����


    return 0;
}