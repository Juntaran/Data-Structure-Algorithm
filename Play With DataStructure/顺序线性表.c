/*顺序线性表*/

#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;


/*初始化线性表*/
Status InitList (SqList *L)
{
    L->length = 0;
    return OK;
}

/*访问元素*/
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*遍历输出该线性表*/
Status ListTraverse( SqList L ){
	
	int i;
	for( i=0; i<L.length; i++ ){
//		visit(L.data[i]);
		printf("%d ",L.data[i]);
	}
	printf("输出完毕！\n");
	return OK;
}

/*清空线性表*/
Status ClearList ( SqList *L ){
	L->length = 0;
	printf("清空线性表成功！\n");
	return OK;
}

/*判断线性表是否为空*/
Status ListIsEmpty ( SqList L ){
	if( L.length == 0 ){
		printf("线性表为空！\n");
		return TRUE;
	}else{
		printf("线性表不为空！\n");
		return FALSE;
	}
}

/*返回线性表长度*/
int ListLength ( SqList L ){
	printf("当前线性表长度为%d\n",L.length);
	return L.length;
}


/*用e返回L中第i个元素的值*/
Status GetElem ( SqList L, int i, ElemType *e )
{
    if ( L.length == 0 || i < 1 || i > L.length )
    {
        printf("Error!\n");
        return ERROR;
    }
    else
    {
        *e = L.data[i-1];
        return OK;
    }
}

/*在L中第i个位置插入新的元素e*/
Status ListInsert ( SqList *L, int i, ElemType e ){
	
	if ( L->length == MAXSIZE ){
		printf("线性表已满！\n");
		return ERROR;
	}
	if ( i<1 || i>L->length+1 ){
		printf("插入位置有错！\n");
		return ERROR;
	}
	if ( i <= L->length ){
		int k;
		for( k=L->length-1; k>=i-1; k-- ){
			L->data[k+1] = L->data[k];
		}
	}
	L->data[i-1] = e;
	L->length++;
	printf("成功在第%d位置上插入%d！\n",i,e);
	
	return OK;
}

/*在L中第i个位置删除该元素e*/
Status ListDelete ( SqList *L, int i, ElemType *e ){
	
	if ( L->length == 0 ){
		printf("该线性表为空！\n");
		return ERROR;
	}
	if ( i<1 || i>L->length ){
		printf("删除位置有错！\n");
		return ERROR;
	}
	*e = L->data[i-1];
	if ( i < L->length ){
		
		int k;
		for( k=i; k<L->length; k++ ){
			L->data[k-1] = L->data[k];
		}
	}
	L->length --;
	printf("成功在第%d位置上删除%d！\n",i,*e);
	
	return OK;
}

/*查询第一个e所在的位置*/
Status LocateElem( SqList L, ElemType e ){
	
	if( L.length == 0 ){
		return 0;
	}
	int i;
	for( i=0; i<L.length; i++ ){
		if( L.data[i] == e ){
			printf("成功查询到第一个e所在位置为%d\n",i+1);
			break;
		}
	}
	if( i >= L.length ){
		printf("不存在该元素\n");
		return 0;
	}
	return i+1;
}

/*将所有在线性表Lb中但不在La中的元素插入到La*/
void unionL( SqList *La, SqList Lb ){
	
	int La_len,Lb_len,i;
	ElemType e;
	La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
	printf("%d,%d\n",La_len,Lb_len);
	for( i=1; i<=Lb_len; i++ ){
		GetElem( Lb, i, &e );
		if(!LocateElem( *La,e )){
			ListInsert( La, ++La_len, e);
		}
	}
}




int main(){
	
	SqList L;
	ElemType e;
	Status i;
	int j;
	
	i = InitList (&L);
	printf ("初始化L后：L.length=%d\n",L.length);
	
	ListInsert ( &L, 1, 3 );	
	GetElem ( L,1,&e);
	printf ("第1个元素的值为：%d\n",e);
	
	ListInsert ( &L, 1, 2 );	
	GetElem ( L,1,&e);
	printf ("第1个元素的值为：%d\n",e);
	GetElem ( L,2,&e);
	printf ("第2个元素的值为：%d\n",e);	
	ListLength (L);
	
	LocateElem( L,3 );
	ListTraverse(L);
	ListIsEmpty(L);

	//构造一个有10个数的Lb
    SqList Lb;
    i = InitList(&Lb);
    for( j=6; j<=15; j++ ){
		i = ListInsert(&Lb,1,j);
	}
	ListTraverse(L);
    ListTraverse(Lb);   
	unionL(&L,Lb);
	ListTraverse(L);
	
	ListDelete ( &L, 1, &e );
	ListLength (L);
	ListTraverse(L);
	
	ClearList(&L);
	ListTraverse(L);
	ListIsEmpty(L);
	
	return 0;
	
}