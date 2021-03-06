#include<stdio.h>  
#include<string.h>  
#include<malloc.h>  
#include<queue>  
using namespace std;  
char str[1000000+100];  
  
struct node  
{  
    int count;  
    struct node *next[26];  
    struct node *fail;  
    void init()  
    {  
        int i;  
        for(i=0;i<26;i++)  
            next[i]=NULL;  
        count=0;  
        fail=NULL;  
    }  
}*root;  
void insert()  
{  
    int len,k;  
    node *p=root;  
    len=strlen(str);  
    for(k=0;k<len;k++)  
    {  
        int pos=str[k]-'a';  
        if(p->next[pos]==NULL)  
        {  
            p->next[pos]=new node;  
            p->next[pos]->init();  
            p=p->next[pos];  
        }  
        else   
            p=p->next[pos];  
    }  
    p->count++;  
}  
void getfail()  
{  
    int i;  
       node *p=root,*son,*temp;  
       queue<struct node *>que;  
       que.push(p);   
       while(!que.empty())  
       {  
           temp=que.front();  
           que.pop();  
           for(i=0;i<26;i++)  
           {  
               son=temp->next[i];  
               if(son!=NULL)  
               {  
                   if(temp==root) {son->fail=root;}  
                   else  
                   {  
                       p=temp->fail;  
                       while(p)  
                       {  
                           if(p->next[i])  
                           {  
                               son->fail=p->next[i];  
                               break;  
                           }  
                           p=p->fail;  
                       }  
                       if(!p)  son->fail=root;  
                   }  
                   que.push(son);  
               }  
           }  
       }  
}  
void query()  
{  
    int len,i,cnt=0;  
    len=strlen(str);  
    node *p,*temp;  
    p=root;  
    for(i=0;i<len;i++)  
    {  
        int pos=str[i]-'a';  
        while(!p->next[pos]&&p!=root)  p=p->fail;        
        p=p->next[pos];//  
        if(!p) p=root;//  
        temp=p;  
        /*不要用*temp=*p  因为*p表示一个node，而*temp也表示一个node 但是由于*temp没有分配空间 所以是不能进行赋值的 但是可以用temp指针去指向p*/  
        while(temp!=root)  
        {  
            if(temp->count>=0)   
            {  
                cnt+=temp->count;  
                temp->count=-1;    
            }  
            else break;   
            temp=temp->fail;   
        }  
    }  
    printf("%d\n",cnt);  
}  
int main()  
{  
    int cas,n;  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        root=new node;  
        root->init();  
        root->fail=NULL;  
        scanf("%d",&n);  
        int i;  
        getchar();  
        for(i=0;i<n;i++)  
        {  
            gets(str);  
            insert();  
        }  
        getfail();  
        gets(str);  
        query();  
    }  
    return 0;  
}  