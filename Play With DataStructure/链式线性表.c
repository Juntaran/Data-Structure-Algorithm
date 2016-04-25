#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;


/*结点由存放数据元素的数据域和存放后继结点地址的指针域组成*/
typedef struct Node
{

    ElemType data;
    struct Node *next;
} Node;
typedef struct Node * LinkList;		/*把 struct Node * 定义成了新类型 LinkList,这个类型是一个结构体的指针*/

/*初始化线性表 */
Status InitList(LinkList *L){
	
	*L = (LinkList)malloc(sizeof(Node));	/*产生头结点，并使L指向此头结点*/
	if(!(*L)){				/*存储分配失败*/
		printf("初始化线性表失败！\n");
		return ERROR;
	}
	(*L)->next = NULL;		/*指针域为空*/
	printf("初始化线性表成功！\n");
	return OK;
}

/*获得线性表长度*/
int ListLength(LinkList L){
	LinkList p = L->next;
	int i;
	while(p){
		i++;
		p = p->next;
	}
	printf("线性表长度为%d\n",i);
	return i;
}

/*判断线性表是否为空*/
Status ListEmpty(LinkList L){
	
	if(L->next != NULL){
		printf("该线性表不为空！\n");
		return FALSE;
	}else{
		printf("该线性表为空！\n");
		return TRUE;
	}
}

/*清空线性表*/
Status ClearList(LinkList *L){
	
	LinkList p,q;
	p = (*L)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	printf("清空完毕！\n");
	return OK;
	
}


/*在第i个位置之前插入新的数据元素e，L长度+1*/
/*在p和p->next中间插入s 
	s->next = p->next   p->next = s*/
Status InsertList(LinkList *L,int i,ElemType e){
	
	int j = 1;
	LinkList p,s;
	p = *L;

/* 46-55行不懂 */	
	while( p&&j < i ){		/* 寻找第i个结点 */
		
		p = p->next;
		++j;
	}
	if( !p || j>i ){		/* 第i个元素不存在 */
		printf("第%d个元素不存在！",i);
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("在第%d个位置插入成功！\n",i);
	return OK;
}

/*删除第i个位置上的元素，L长度-1*/
/* p->next = q->next 越过了q */
Status DeleteList(LinkList *L,int i){
	
	int j = 1;
	LinkList p,q;
	p = *L;
	while( p->next && j < i ){				/* 遍历寻找第i个元素 */
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i ){
		printf("不存在第%d个结点！\n",i);	/* 第i个元素不存在 */
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("在第%d个位置删除成功！\n",i);
	return OK;
}

/*查询第一个为e元素的位置*/
int LocateElem(LinkList L,ElemType e){
	
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		if( p->data == e ){
			printf("第一个元素为%d的位置为%d\n",e,i);
			return i;
		}
		p = p->next;
	}
	printf("线性表中没有该元素%d\n",i);
	return FALSE;
}

/*获取第i个元素的值*/
Status GetElem(LinkList L, int i, ElemType *e){
	
	LinkList p;
	p = L->next;
	int j = 1;
	while( p && j < i ){	/* p不为空或者计数器j还没有等于i时，循环继续 */
		p = p->next;
		j++;
	}
	if( !p || j>i ){
		return ERROR;		/*  第i个元素不存在 */
	}
	*e = p->data;
	printf("第%d个元素的值为%d\n",i,*e);
	return OK;
}

Status visit(ElemType c){
	
	printf("%d ",c);
	return OK;
}

/* 操作结果：依次对L的每个数据元素输出 */
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