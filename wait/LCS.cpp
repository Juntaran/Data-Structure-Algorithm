//只能打印一个最长公共子序列
#include <iostream>
using namespace std;

const int X = 100, Y = 100;        //串的最大长度
char result[X+1];                    //用于保存结果
int count=0;                        //用于保存公共最长公共子串的个数

/*功能：计算最优值
 *参数：
 *        x:字符串x
 *        y:字符串y
 *        b:标志数组
 *        xlen:字符串x的长度
 *        ylen:字符串y的长度
 *返回值：最长公共子序列的长度
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
	cout << "计算最优值效果图如下所示：" << endl;
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

	//打印结果如下所示
	for(int i = 0; i < lcs_max_len; i++)
	{
		cout << result[i];
	}
	cout << endl;
	return 0;
}