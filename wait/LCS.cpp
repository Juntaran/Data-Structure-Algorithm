//ֻ�ܴ�ӡһ�������������
#include <iostream>
using namespace std;

const int X = 100, Y = 100;        //������󳤶�
char result[X+1];                    //���ڱ�����
int count=0;                        //���ڱ��湫��������Ӵ��ĸ���

/*���ܣ���������ֵ
 *������
 *        x:�ַ���x
 *        y:�ַ���y
 *        b:��־����
 *        xlen:�ַ���x�ĳ���
 *        ylen:�ַ���y�ĳ���
 *����ֵ������������еĳ���
 *
 */
int Lcs_Length(string x, string y, int b[][Y+1],int xlen,int ylen)
{
	int i = 0;
	int j = 0;

	int c[X+1][Y+1];
	for (i = 0; i<=xlen; i++)
	{
		c[i][0]=0;
	}
	for (i = 0; i <= ylen; i++ )
	{
		c[0][i]=0;
	}
	for (i = 1; i <= xlen; i++)
	{

		for (j = 1; j <= ylen; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			}
			else if (c[i-1][j] > c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else if(c[i-1][j] <= c[i][j-1])
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}

		}
	}
	cout << "��������ֵЧ��ͼ������ʾ��" << endl;
	for(i = 1; i <= xlen; i++)
	{
		for(j = 1; j < ylen; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return c[xlen][ylen];
}

void Display_Lcs(int i, int j, string x, int b[][Y+1],int current_Len)
{
	if (i ==0 || j==0)
	{
		return;
	}
	if(b[i][j]== 1)
	{
		current_Len--;
		result[current_Len]=x[i- 1];
		Display_Lcs(i-1, j-1, x, b, current_Len);
	}
	else
	{
		if(b[i][j] == 2)
		{
			Display_Lcs(i-1, j, x, b, current_Len);
		}
		else
		{
			if(b[i][j]==3)
			{
				Display_Lcs(i, j-1, x, b, current_Len);
			}
			else
			{
				Display_Lcs(i-1,j,x,b, current_Len);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	string x = "ABCBDAB";
	string y = "BDCABA";
	int xlen = x.length();
	int ylen = y.length();

	int b[X + 1][Y + 1];

	int lcs_max_len = Lcs_Length( x, y, b, xlen,ylen );
	cout << lcs_max_len << endl;

	Display_Lcs( xlen, ylen, x, b, lcs_max_len );

	//��ӡ���������ʾ
	for(int i = 0; i < lcs_max_len; i++)
	{
		cout << result[i];
	}
	cout << endl;
	return 0;
}