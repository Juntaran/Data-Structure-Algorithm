#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

char* InitStr(char* pStr)
{
	assert(pStr != NULL);
	//����ַ�
	int nCount = 0;
	int nLenOldStr = strlen(pStr);
	int nLenNewStr = (nLenOldStr << 1) + 3;//ab -> $#a#b#0
	char* pNewStr = new char[nLenNewStr];
	pNewStr[nCount++] = '$';
	for (int i = 0;i < nLenOldStr;i++)
	{
		pNewStr[nCount++] = '#';
		pNewStr[nCount++] = pStr[i];
	}
	pNewStr[nCount++] = '#';
	pNewStr[nCount] = '\0';

	return pNewStr;
}

int Manacher(char* pStr)
{
	assert(pStr != NULL);
	int nId = 1;
	int nMx = 0;
	int j = 0;
	int nLongest = 0;
	char* pNewStr = InitStr(pStr);
	int nLenStr = strlen(pNewStr);
	int* p = new int[nLenStr];
	memset(p,0,sizeof(int) * nLenStr);
	for (int i = 1;pNewStr[i] != '\0';i++)
	{
		if (nMx > i)//�ܽ��֮ǰ�Ľ��
		{
			p[i] = min(p[(nId << 1) - i],nMx - i);//id = (i + j) >> 1;
		}
		else
		{
			p[i] = 1; //�����Ӵ����ȵ��ڱ���
		}
		//����ƥ��
		while(pNewStr[i + p[i]] == pNewStr[i - p[i]])
		{
			p[i]++;
		}
		//��չ�Ѿ�ƥ�����Զ����
		if (i + p[i] > nMx)
		{
			nMx = i + p[i];
			nId = i;
		}
		//�ҳ����ֵƥ���ַ�����
		if (pNewStr[i] != '#')
		{
			nLongest = max(nLongest,p[i]);
		}
	}
	delete[] pNewStr;
	delete[] p;
	return nLongest - 1;
}

int main()
{
	//char strArr[] = "122122212";
	char strArr[] = "12212221";
	cout<<Manacher(strArr)<<endl;
	system("pause");
	return 1;
}