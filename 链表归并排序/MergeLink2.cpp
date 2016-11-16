#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} LNode, *LinkList;

Node* getMiddle(LinkList L) {//��ͷ�������
    LNode *mid, *midl, *p;
    midl = NULL, p = mid = L;
    while (p != NULL && p->next != NULL) {//���ÿ���ָ����������м�λ�ò�������1��Ϊ2
        p = p->next->next;
        midl = mid;
        mid = mid->next;
    }
    midl->next = NULL;//������1��2
    return mid;
}

void printList(LinkList L) {
    LNode *p;
    p = L;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;;
}

void Merge(LinkList &La, LinkList Lb) {//��������������La��Lb�ϲ���һ����������La
    LNode *pa = La, *pb = Lb;
    LinkList Lc = NULL;
    LNode *q = NULL;
    if (pa->data <= pb->data) {
        Lc = q = pa;
        pa = pa->next;
    }
    else {
        Lc = q = pb;
        pb = pb->next;
    }
    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            q->next = pa, pa = pa->next, q = q->next;
        }
        else {
            q->next = pb, pb = pb->next, q = q->next;
        }
    }
    if (pa == NULL) q->next = pb;
    else if (pb == NULL) q->next = pa;
    La = Lc;//La����ָ��ϲ��������
}

void MergeSort(LinkList &L) {//ע�����õ�ʹ��
    if (L == NULL || L->next == NULL) return;//��������С�ڵ���1ʱ�������ٷ�
    LinkList La, Lb;
    Lb = getMiddle(L);
    La = L;
    MergeSort(La);
    MergeSort(Lb);
    Merge(La, Lb);
    L = La;//���صĽ������
}

void DestroyList(LinkList &L) {
    LNode *p, *q;
    p = q = L;
    while (p != NULL) {
        q = q->next;
        free(p);
        p = q;
    }
}

int main() {
    int len = 10, i;
    LinkList L;
    LNode *p;
    if ((L = (LinkList)malloc(sizeof(LNode))) == NULL) {
        cerr << "Error in allocate memory!" << endl;
        return -1;
    }
    srand(time(NULL));
    L->data = rand(); 
	L->next = NULL;
    for (i = 1; i < len; i++) {
        if ((p = (LNode*)malloc(sizeof(LNode))) == NULL) {
            cerr << "Error in allocate memory!" << endl;
            DestroyList(L);
            return -1;
        }
        p->data = rand();
        p->next = L->next;
        L->next = p;//ͷ��
    }
    cout << "The list before sorting:" << endl;
    printList(L);

    MergeSort(L);
    cout << "\nThe list after sorting:" << endl;
    printList(L);

    DestroyList(L);
}
