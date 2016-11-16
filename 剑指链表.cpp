#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

//�������ĩβ���һ���ڵ� 
struct ListNode
{
	int m_nValue;
	ListNode * m_pNext;
};
//�ҵĳ��� ע���һ��������һ��ָ��ָ���ָ�� ����һ���������в���һ���ڵ�ʱ���²���Ľڵ���������ͷָ��
void AddToTail1(ListNode ** pHead,int value)
{
	//�����½ڵ�
	ListNode * newNode=new ListNode();
	newNode->m_nValue=value;
	newNode->m_pNext=NULL;
    

	if(pHead == NULL)
		return;

	//֮ǰ�ٿ����˿���������
	if(*pHead == NULL)
	{
		*pHead=newNode;
		return;
	}
	
	//�����һ���ڵ�
	ListNode * p = *pHead;
	ListNode * q = NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->m_pNext;
	}

    //���뵽�������
	q->m_pNext=newNode;

	//û���жϵ�����Ϊ�յ�ʱ�򣡣�
}
//���ϵ����ӣ�δ��֤pHeadΪ�յ����

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
//��ͷ��β��ӡ�б�
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