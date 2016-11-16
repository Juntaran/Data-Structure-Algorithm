/*************************************************************************
	> File Name: LinkSort.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: 2016年08月24日 星期三 17时23分04秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

/************************************************************************/
// 初始准备工作

// 链表结构体
struct ListNode
{
	int val;
	struct ListNode* next;
};

// 构造链表
ListNode* createList(int data[], int length)
{
	struct ListNode* head;
	struct ListNode* p;
	struct ListNode* q;
	head = p = (ListNode*)malloc(sizeof(ListNode));
	head->val = data[0];
	for (int i = 1; i < length; ++i)
	{
		q = (ListNode*)malloc(sizeof(ListNode));
		q->val = data[i];
		p->next = q;
		p = q;
	}
	p->next = NULL;
	return head;
}

// 顺序输出链表
void PrintList(ListNode* head)
{
	if (head == NULL)
		return;
	ListNode* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

/************************************************************************/

/************************************************************************/
// 快速排序

// 交换元素
void swap(ListNode* a, ListNode* b)
{
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}

// 找到Flag
ListNode* getFlag(ListNode* left, ListNode* right)
{
	ListNode* p = left;
	ListNode* q = left->next;
	int key = p->val;
	while (q != right)
	{
		if (q->val < key)
		{
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(left, p);
	return p;
}

// 核心代码
void LinkQuickSort(ListNode* left, ListNode* right)
{
	if (left != right)
	{
		ListNode* flag = getFlag(left, right);
		LinkQuickSort(left, flag);
		LinkQuickSort(flag->next, right);
	}
}

/************************************************************************/

/************************************************************************/
// 归并排序

ListNode* Merge(ListNode* a, ListNode* b);

// 分割链表函数
void SplitLink(ListNode* source, ListNode** a, ListNode** b)
{
	ListNode* fast;
	ListNode* slow;
	if (source==NULL || source->next==NULL)
	{
		*a = source;
		*b = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		
		*a = source;
		*b = slow->next;
		slow->next = NULL;
	}
}


// 排序
void LinkMergeSort(ListNode** head)
{
	ListNode* newHead = *head;
	ListNode* a;
	ListNode* b;
	
	if (newHead==NULL || newHead->next==NULL)
		return;
	
	// 分割链表为a,b
	SplitLink(newHead, &a, &b);
	
	// 递归
	LinkMergeSort(&a);
	LinkMergeSort(&b);
	
	// 合并a, b
	*head = Merge(a, b);					
}

// 合并已排序链表
ListNode* Merge(ListNode* a, ListNode* b)
{
	ListNode* newHead = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	
	// 递归
	if ( a->val <= b->val)
	{
		newHead = a;
		newHead->next = Merge(a->next, b);
	}
	else
	{
		newHead = b;
		newHead->next = Merge(a, b->next);
	}
	return newHead;
}

/************************************************************************/


int main()
{
	int length = 10;
	int data[] = {9,5,6,8,4,4,7,2,3,7};
	ListNode* testQuickSort = createList(data, length);
	ListNode* testMergeSort = createList(data, length);
	printf("Before sort:\n");
	PrintList(testQuickSort);
	
	printf("Quick Sort:\n");
	LinkQuickSort(testQuickSort, NULL);
	PrintList(testQuickSort);
	
	printf("Merge Sort:\n");
	LinkMergeSort(&testMergeSort);
	PrintList(testMergeSort);
	return  0;
}