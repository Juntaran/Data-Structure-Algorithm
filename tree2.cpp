#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> > ans;
        queue<TreeNode* > Q;
        if(pRoot)
            Q.push(pRoot);
        int num = 1;
        int dept=0;
        while(!Q.empty())
        {
            int num1=0;
            vector<int >vc;
            for(int i=0; i<num; i++)
            {
                TreeNode* tmp=Q.front();
                Q.pop();
                if(tmp->left)
                    Q.push(tmp->left),num1++;
                if(tmp->right)
                    Q.push(tmp->right),num1++;
                vc.push_back(tmp->val);
            }
            ans.push_back(vc);
            dept++;
            num=num1;
        }
        return ans;
    }
} f;

int main()
{
    TreeNode f1=TreeNode(1);
    TreeNode f2=TreeNode(2);
    TreeNode f3=TreeNode(3);
    TreeNode f4=TreeNode(4);
    f1.left=&f2;
    f2.left=&f4;
    f1.right=&f3;
    TreeNode* root = &f1;
    vector<vector<int> > c = f.Print(root);
    for(int i=0; i<=2; i++)
    {
        vector<int > tmp = c[i];
        for(int j=0; j<tmp.size(); j++)
            printf("%d ",tmp[j]);
        puts("");
    }
    return 0;
}