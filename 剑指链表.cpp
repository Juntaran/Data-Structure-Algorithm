#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

//向链表的末尾添加一个节点 
struct ListNode
{
	int m_nValue;
	ListNode * m_pNext;
};
//我的程序 注意第一个参数是一个指向指针的指针 当向一个空链表中插入一个节点时，新插入的节点就是链表的头指针
void AddToTail1(ListNode ** pHead,int value)
{
	//申请新节点
	ListNode * newNode=new ListNode();
	newNode->m_nValue=value;
	newNode->m_pNext=NULL;
    

	if(pHead == NULL)
		return;

	//之前少考虑了空链表的情况
	if(*pHead == NULL)
	{
		*pHead=newNode;
		return;
	}
	
	//找最后一个节点
	ListNode * p = *pHead;
	ListNode * q = NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->m_pNext;
	}

    //插入到链表最后
	q->m_pNext=newNode;

	//没有判断当链表为空的时候！！
}
//书上的例子，未验证pHead为空的情况

void AddToTail(ListNode ** pHead,int value)
{
	ListNode * pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext  = NULL;

	if(*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode * p = *pHead;
		while(p->m_pNext != NULL)
		{
			p = p->m_pNext;
		}
		p-> m_pNext = pNew;
	}
}

void AddToTail2(ListNode *pHead, int value)
{ 
	ListNode * pNew2 = new ListNode();
	pNew2->m_nValue = value;
	pNew2->m_pNext  = NULL;
	
	if(pHead == NULL)
	{
		pHead = pNew2;
	}
	else
	{
		ListNode * p = pHead;
		while( p->m_pNext != NULL )
		{
			p = p->m_pNext;
		}
		p->m_pNext = pNew2;
	}
}

ListNode * CreateLink(int a[],int k)
{
	ListNode * Head=NULL,*q=NULL;
	for(int i=0;i<k;i++)
	{
		ListNode * pNew=new ListNode();
        pNew->m_nValue=a[i];
   	    pNew->m_pNext=NULL;

		if(Head==NULL)
		{
			Head=pNew;
			q=pNew;
		}
		else
		{
			q->m_pNext=pNew;
			q=q->m_pNext;
		}
	}
	return Head;
}
//从头到尾打印列表
void printLink(ListNode * pHead)
{
	ListNode *p=pHead;
	while(p)
	{
		cout<<p->m_nValue<<" ";
		p=p->m_pNext;
	}
	cout<<endl;
}
int main()
{
	int a[]={1,2,3};
	ListNode * Head=CreateLink(a,3);
	printLink(Head);

	AddToTail1(&Head,6);
	printLink(Head);
	AddToTail2(Head,7);
	printLink(Head);
	return 0;
}