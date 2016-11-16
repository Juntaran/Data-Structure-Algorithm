#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256						// ascii����256���ַ�����ÿ�������ӽڵ������256��
#define MAXLEN 256					// �����Ϊ256

struct TrieNode
{
	int count;
	TrieNode* next[MAX];
};

// ����һ������
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

//����������ÿ�����ʣ��Իس��������򵥴ʱ��������У�����*ֹͣ���Ĵ���
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

//����������
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
//����仰���Կ����ڵݹ�����ӽڵ�ǰ���ӽڵ��ֵ�Ѿ����뵽��������
		Traverse(curP->next[i]);
		pos--;
	}
	return;
}

//����һ�������ǲ���������
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