#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//二叉树节点
typedef struct tree
{
    int data;
    struct tree *pLeft;
    struct tree *pRight;
} Tree;
//队列
typedef struct queue
{
    struct node *pFront;
    struct node *pBehind;
    int size;
} Queue;
//栈
typedef struct stack
{
    struct node *pBottom;
    struct node *pTop;
    int size;
} Stack;
//普通节点
typedef struct node
{
    struct tree * data;
    struct node * next;
} Node;
//生成二叉搜索树
Tree * create(Tree * pRoot, int val)
{
    if(pRoot == NULL)
    {
        pRoot = (Tree *)malloc(sizeof(Tree));
        pRoot->data = val;
        pRoot->pLeft = NULL;
        pRoot->pRight = NULL;
    }
    else
    {
        if(val < pRoot->data)
        {
            pRoot->pLeft = create(pRoot->pLeft, val);
        }
        else
        {
            pRoot->pRight = create(pRoot->pRight, val);
        }
    }
    return pRoot;
}
//循环遍历生成二叉树
Tree * createTree(Tree * pRoot)
{
    for(int i=1; i<=15; i++)
    {
        int val = rand()%100+1000;
        pRoot = create(pRoot, val);
    }
    return pRoot;
}
//中序遍历二叉树
void tarverse(Tree * pRoot)
{
    if(pRoot != NULL)
    {
        tarverse(pRoot->pLeft);
        printf("%d\n", pRoot->data);
        tarverse(pRoot->pRight);
    }
}
//前序遍历二叉树
void pretarverse(Tree * pRoot)
{
    if(pRoot != NULL)
    {
        printf("%d\n", pRoot->data);
        tarverse(pRoot->pLeft);
        tarverse(pRoot->pRight);
    }
}
//队列初始化
Queue * init()
{
    Queue * pQueue = (Queue *)malloc(sizeof(Queue));
    if(pQueue == NULL)
    {
        printf("init queue failed!\n");
        exit(0);
    }
    pQueue->pFront = NULL;
    pQueue->pBehind = NULL;
    pQueue->size = 0;
    return pQueue;
}
//判断队列是否为空
int empty(Queue * pQueue)
{
    if(pQueue->size == 0)
    {
        return 1;
    }
    return 0;
}
//队列中添加数据
void in(Queue * pQueue, Tree * pTree)
{
    Node * pNode = (Node *)malloc(sizeof(Node));
    if(pNode == NULL)
    {
        printf("queue in data failed\n");
        exit(0);
    }
    pNode->data = pTree;
    pNode->next = NULL;
    if(empty(pQueue))
    {
        pQueue->pFront = pNode;
    }
    else
    {
        pQueue->pBehind->next = pNode;
    }
    pQueue->pBehind = pNode;
    pQueue->size += 1;
}
//队列中移除并返回数据
Tree * out(Queue * pQueue)
{
    if(empty(pQueue))
    {
        printf("queue is empty\n");
        exit(0);
    }
    Node * pNode = pQueue->pFront;
    pQueue->pFront = pNode->next;
    pQueue->size -= 1;
    Tree * pTree = pNode->data;
    delete pNode;
    pNode = NULL;
    return pTree;
}
Tree * pop(Queue * pQueue)
{
    if(empty(pQueue))
    {
        printf("queue is empty!\n");
        exit(0);
    }
    Tree * pNode = pQueue->pBehind->data;
    return pNode;
}
void qtarverse(Queue * pQueue)
{
    if(empty(pQueue))
    {
        printf("queue is empty!\n");
        exit(0);
    }
    Node * pNode = pQueue->pFront;
    while(pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = pNode->next;
    }
}
//二叉树按层排印
void printLevel(Tree * pRoot)
{
    if(pRoot == NULL)
    {
        printf("binary tree is empty\n");
        exit(0);
    }
    Tree * pTree;
    Queue * pQueue = init();
    in(pQueue, pRoot);
    while(!empty(pQueue))
    {
        pTree = out(pQueue);
        printf("%d\n", pTree->data);
        if(pTree->pLeft != NULL)
        {
            in(pQueue, pTree->pLeft);
        }
        if(pTree->pRight != NULL)
        {
            in(pQueue, pTree->pRight);
        }
    }
}
Stack * stackInit()
{
    Stack * pStack = (Stack *)malloc(sizeof(Stack));
    if(pStack == NULL)
    {
        printf("init stack is failed!\n");
        exit(0);
    }
    pStack->pBottom = NULL;
    pStack->pTop = NULL;
    pStack->size = 0;
    return pStack;
}
int stackEmpty(Stack * pStack)
{
    if(pStack->size == 0)
    {
        return 1;
    }
    return 0;
}
void stackIn(Stack * pStack, Tree * pTree)
{
    Node * pNode = (Node *)malloc(sizeof(Node));
    if(pNode == NULL)
    {
        printf("stack in number failed!\n");
        exit(0);
    }
    pNode->data = pTree;
    if(stackEmpty(pStack))
    {
        pNode->next = NULL;
        pStack->pBottom = pNode;
        pStack->pTop = pNode;
    }
    else
    {
        pNode->next = pStack->pTop;
        pStack->pTop = pNode;
    }
    pStack->size += 1;
}
Tree * stackOut(Stack * pStack)
{
    if(stackEmpty(pStack))
    {
        printf("stack is empty\n");
        exit(0);
    }
    Node * pNode = pStack->pTop;
    Tree * pTree = pNode->data;
    pStack->pTop = pNode->next;
    pStack->size -= 1;
    delete pNode;
    pNode = NULL;
    return pTree;
}
//二叉树深度优先遍历
void dfs(Tree * pRoot)
{
    if(pRoot == NULL)
    {
        printf("binary tree is empty!\n");
        exit(0);
    }
    Stack * pStack = stackInit();
    stackIn(pStack, pRoot);
    while(!stackEmpty(pStack))
    {
        Tree * pTree = stackOut(pStack);
        printf("%d\n", pTree->data);
        if(pTree->pRight != NULL)
        {
            stackIn(pStack, pTree->pRight);
        }
        if(pTree->pLeft != NULL)
        {
            stackIn(pStack, pTree->pLeft);
        }
    }
}
//判断二叉树是否对称
int judgeTreeIsSym(Tree * pRoot01, Tree * pRoot02)
{
    if(pRoot01 == NULL && pRoot02 == NULL)
    {
        return 1;
    }
    if(pRoot01 == NULL || pRoot02 == NULL)
    {
        return 0;
    }
    if(judgeTreeIsSym(pRoot01->pLeft, pRoot02->pRight) && judgeTreeIsSym(pRoot01->pRight, pRoot02->pLeft))
    {
        return 1;
    }
    return 0;
}
int main()
{
    Tree * pRoot = NULL;
    pRoot = createTree(pRoot);
	printf("中序遍历\n");
    tarverse(pRoot);
    printf("\n\n");
	printf("前序遍历\n");
	pretarverse(pRoot);
	printf("\n\n");
	printf("层序遍历\n");
    printLevel(pRoot);
    printf("\n\n");
	printf("深度优先\n");
    dfs(pRoot);
    return 0;
}