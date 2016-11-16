#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256						// ascii码有256个字符，故每棵树的子节点最多有256个
#define MAXLEN 256					// 单词最长为256

struct TrieNode
{
	int count;
	TrieNode* next[MAX];
};

// 插入一个单词
void Insert(char *word,TrieNode *root)

{
	int i;
	TrieNode *cur;
	if(word[0]=='\0')
		return;
	cur=root;
	for(i=0; word[i]!='\0'; i++)
	{
		if(cur->next[word[i]]==NULL)
		{
			TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
			memset(newNode,0,sizeof(TrieNode));
			cur->next[word[i]]=newNode;
		}
		cur=cur->next[word[i]];
	}

	cur->count++;
	return;
}

//创建树输入每个单词，以回车结束，则单词被插入树中，碰到*停止树的创建
void Construct(TrieNode *&root)
{
	char inStr[MAXLEN];
	int size=0;
	root = (TrieNode *)malloc(sizeof(TrieNode));
	memset(root,0,sizeof(TrieNode));
	while(1)
	{
		scanf("%s",inStr);
		if(strcmp(inStr,"*")==0)
			break;
		Insert(inStr,root);
	}
	return;
}

//遍历整棵树
void Traverse(TrieNode *curP)
{
	static char theWord[MAXLEN];
	static int pos=0;
	int i;
	if(curP==NULL)
		return;
	if(curP->count)
	{
		theWord[pos]='\0';
		printf("%s:%d\n",theWord,curP->count);
	}
	for(i=0; i<MAX; i++)
	{
		theWord[pos++]=i;
//从这句话可以看出在递归调用子节点前，子节点的值已经加入到单词中了
		Traverse(curP->next[i]);
		pos--;
	}
	return;
}

//查找一个单词是不是在树中
int Find(TrieNode *root,char *word)
{
	int i;
	TrieNode *cur;
	cur=root;
	for(i=0; word[i]!='\0'; i++)
	{
		if(cur->next[word[i]]==NULL)
		{
			return false;
		}
		cur=cur->next[word[i]];
	}

	if(cur->count)
		return 1;
	else
		return 0;
}

int main()
{
	TrieNode *root;
	char str[MAXLEN];
	Construct(root);
	printf("\n");
	Traverse(root);
	printf("\n");
	while(1)
	{
		scanf("%s",str);
		if(strcmp(str,"*")==0)
			break;
		printf("%s:%d\n",str,Find(root,str));
	}

	return 0;
}