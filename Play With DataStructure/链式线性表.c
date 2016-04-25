#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;


/*����ɴ������Ԫ�ص�������ʹ�ź�̽���ַ��ָ�������*/
typedef struct Node
{

    ElemType data;
    struct Node *next;
} Node;
typedef struct Node * LinkList;		/*�� struct Node * ������������� LinkList,���������һ���ṹ���ָ��*/

/*��ʼ�����Ա� */
Status InitList(LinkList *L){
	
	*L = (LinkList)malloc(sizeof(Node));	/*����ͷ��㣬��ʹLָ���ͷ���*/
	if(!(*L)){				/*�洢����ʧ��*/
		printf("��ʼ�����Ա�ʧ�ܣ�\n");
		return ERROR;
	}
	(*L)->next = NULL;		/*ָ����Ϊ��*/
	printf("��ʼ�����Ա�ɹ���\n");
	return OK;
}

/*������Ա���*/
int ListLength(LinkList L){
	LinkList p = L->next;
	int i;
	while(p){
		i++;
		p = p->next;
	}
	printf("���Ա���Ϊ%d\n",i);
	return i;
}

/*�ж����Ա��Ƿ�Ϊ��*/
Status ListEmpty(LinkList L){
	
	if(L->next != NULL){
		printf("�����Ա�Ϊ�գ�\n");
		return FALSE;
	}else{
		printf("�����Ա�Ϊ�գ�\n");
		return TRUE;
	}
}

/*������Ա�*/
Status ClearList(LinkList *L){
	
	LinkList p,q;
	p = (*L)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	printf("�����ϣ�\n");
	return OK;
	
}


/*�ڵ�i��λ��֮ǰ�����µ�����Ԫ��e��L����+1*/
/*��p��p->next�м����s 
	s->next = p->next   p->next = s*/
Status InsertList(LinkList *L,int i,ElemType e){
	
	int j = 1;
	LinkList p,s;
	p = *L;

/* 46-55�в��� */	
	while( p&&j < i ){		/* Ѱ�ҵ�i����� */
		
		p = p->next;
		++j;
	}
	if( !p || j>i ){		/* ��i��Ԫ�ز����� */
		printf("��%d��Ԫ�ز����ڣ�",i);
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("�ڵ�%d��λ�ò���ɹ���\n",i);
	return OK;
}

/*ɾ����i��λ���ϵ�Ԫ�أ�L����-1*/
/* p->next = q->next Խ����q */
Status DeleteList(LinkList *L,int i){
	
	int j = 1;
	LinkList p,q;
	p = *L;
	while( p->next && j < i ){				/* ����Ѱ�ҵ�i��Ԫ�� */
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i ){
		printf("�����ڵ�%d����㣡\n",i);	/* ��i��Ԫ�ز����� */
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("�ڵ�%d��λ��ɾ���ɹ���\n",i);
	return OK;
}

/*��ѯ��һ��ΪeԪ�ص�λ��*/
int LocateElem(LinkList L,ElemType e){
	
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		if( p->data == e ){
			printf("��һ��Ԫ��Ϊ%d��λ��Ϊ%d\n",e,i);
			return i;
		}
		p = p->next;
	}
	printf("���Ա���û�и�Ԫ��%d\n",i);
	return FALSE;
}

/*��ȡ��i��Ԫ�ص�ֵ*/
Status GetElem(LinkList L, int i, ElemType *e){
	
	LinkList p;
	p = L->next;
	int j = 1;
	while( p && j < i ){	/* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
		p = p->next;
		j++;
	}
	if( !p || j>i ){
		return ERROR;		/*  ��i��Ԫ�ز����� */
	}
	*e = p->data;
	printf("��%d��Ԫ�ص�ֵΪ%d\n",i,*e);
	return OK;
}

Status visit(ElemType c){
	
	printf("%d ",c);
	return OK;
}

/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L){
	
	LinkList p = L->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main(){
	
	LinkList L;
	ElemType e;
	Status i;
	
	i = InitList(&L);
	ListEmpty(L);
	InsertList(&L,1,3);
	InsertList(&L,1,5);
	GetElem(L,2,&e);
	ListTraverse(L);
	LocateElem(L,2);
	ListLength(L);
	ListEmpty(L);
	DeleteList(&L,1);
	ClearList(&L);
	ListTraverse(L);
	ListLength(L);
	ListEmpty(L);
}