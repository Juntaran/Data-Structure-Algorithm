/*˳�����Ա�*/

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


/*��ʼ�����Ա�*/
Status InitList (SqList *L)
{
    L->length = 0;
    return OK;
}

/*����Ԫ��*/
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*������������Ա�*/
Status ListTraverse( SqList L ){
	
	int i;
	for( i=0; i<L.length; i++ ){
//		visit(L.data[i]);
		printf("%d ",L.data[i]);
	}
	printf("�����ϣ�\n");
	return OK;
}

/*������Ա�*/
Status ClearList ( SqList *L ){
	L->length = 0;
	printf("������Ա�ɹ���\n");
	return OK;
}

/*�ж����Ա��Ƿ�Ϊ��*/
Status ListIsEmpty ( SqList L ){
	if( L.length == 0 ){
		printf("���Ա�Ϊ�գ�\n");
		return TRUE;
	}else{
		printf("���Ա�Ϊ�գ�\n");
		return FALSE;
	}
}

/*�������Ա���*/
int ListLength ( SqList L ){
	printf("��ǰ���Ա���Ϊ%d\n",L.length);
	return L.length;
}


/*��e����L�е�i��Ԫ�ص�ֵ*/
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

/*��L�е�i��λ�ò����µ�Ԫ��e*/
Status ListInsert ( SqList *L, int i, ElemType e ){
	
	if ( L->length == MAXSIZE ){
		printf("���Ա�������\n");
		return ERROR;
	}
	if ( i<1 || i>L->length+1 ){
		printf("����λ���д�\n");
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
	printf("�ɹ��ڵ�%dλ���ϲ���%d��\n",i,e);
	
	return OK;
}

/*��L�е�i��λ��ɾ����Ԫ��e*/
Status ListDelete ( SqList *L, int i, ElemType *e ){
	
	if ( L->length == 0 ){
		printf("�����Ա�Ϊ�գ�\n");
		return ERROR;
	}
	if ( i<1 || i>L->length ){
		printf("ɾ��λ���д�\n");
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
	printf("�ɹ��ڵ�%dλ����ɾ��%d��\n",i,*e);
	
	return OK;
}

/*��ѯ��һ��e���ڵ�λ��*/
Status LocateElem( SqList L, ElemType e ){
	
	if( L.length == 0 ){
		return 0;
	}
	int i;
	for( i=0; i<L.length; i++ ){
		if( L.data[i] == e ){
			printf("�ɹ���ѯ����һ��e����λ��Ϊ%d\n",i+1);
			break;
		}
	}
	if( i >= L.length ){
		printf("�����ڸ�Ԫ��\n");
		return 0;
	}
	return i+1;
}

/*�����������Ա�Lb�е�����La�е�Ԫ�ز��뵽La*/
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
	printf ("��ʼ��L��L.length=%d\n",L.length);
	
	ListInsert ( &L, 1, 3 );	
	GetElem ( L,1,&e);
	printf ("��1��Ԫ�ص�ֵΪ��%d\n",e);
	
	ListInsert ( &L, 1, 2 );	
	GetElem ( L,1,&e);
	printf ("��1��Ԫ�ص�ֵΪ��%d\n",e);
	GetElem ( L,2,&e);
	printf ("��2��Ԫ�ص�ֵΪ��%d\n",e);	
	ListLength (L);
	
	LocateElem( L,3 );
	ListTraverse(L);
	ListIsEmpty(L);

	//����һ����10������Lb
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