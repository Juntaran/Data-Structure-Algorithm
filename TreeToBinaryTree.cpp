#include <iostream>
#include <string>
using namespace std;
//树的节点
struct TreeNode
{
    char element;
    int childNumbers;//孩子结点的个数
    struct TreeNode* child[3];//孩子的数组
    TreeNode() {}
    TreeNode(char ele, int numbers)
    {
        element = ele;
        childNumbers = numbers;
        for (int i=0; i<3; i++)
            child[i] = NULL;
    }
    //重载赋值运算符
    TreeNode& operator = (const TreeNode& other)
    {
        if(this == &other)
            return *this;
        else
        {
            element = other.element;
            childNumbers = other.childNumbers;
            for (int i=0; i<3; i++)
                child[i] = other.child[i];
        }
    }
};
//二叉树的结点
typedef struct BTreeNode
{
    char element;
    BTreeNode *left;
    BTreeNode *right;
    BTreeNode(char ele = 0, BTreeNode *lchild = NULL, BTreeNode *rchild=NULL)
    {
        element = ele;
        left = lchild;
        right = rchild;
    }
} BTreeNode;
//构建树
void CreateTree(TreeNode* &root)
{
    TreeNode *e = new TreeNode('E', 0);
    TreeNode *f = new TreeNode('F', 0);
    TreeNode *b = new TreeNode('B', 2);
    b->child[0] = e;
    b->child[1] = f;
    TreeNode *g = new TreeNode('G', 0);
    TreeNode *d = new TreeNode('D', 1);
    d->child[0]= g;
    TreeNode *c = new TreeNode('C', 0);
    root = new TreeNode('A', 3);
    root->child[0] = b;
    root->child[1] = c;
    root->child[2] = d;
}
//将树转换为二叉树
BTreeNode* TreeToBinaryTree(TreeNode *treeRoot)
{
    if (treeRoot == NULL)
    {
        return NULL;
    }
    BTreeNode* binaryRoot = new BTreeNode; //二叉树的根
    binaryRoot->element = treeRoot->element;
    binaryRoot->left = TreeToBinaryTree(treeRoot->child[0]); //左孩子
    BTreeNode *brotherChild = binaryRoot->left; //兄弟
    for (int i= 1; i<treeRoot->childNumbers; i++)
    {
        brotherChild->right = TreeToBinaryTree(treeRoot->child[i]);
        brotherChild = brotherChild->right;
    }
    return binaryRoot;
}
//二叉树中序输出
void MiddleOrderPrint(BTreeNode *root)
{
    BTreeNode *temp = root;
    if(temp == NULL)
        return;
    else
    {
        MiddleOrderPrint(temp->left);
        cout<<root->element<<" ";
        MiddleOrderPrint(temp->right);
    }
}
int main()
{
    TreeNode *treeRoot;
    CreateTree(treeRoot);
    BTreeNode *binaryRoot = TreeToBinaryTree(treeRoot);
    MiddleOrderPrint(binaryRoot);
    cout<<endl;
    return 0;
}
