// 1. �й������� �����տ����ߵ������ ���Ե�һ�����������ж�
// 2. ����ʹ�û��ݷ�Ѱ��·��

struct Point
{
	int x;
	int y;
};
Point move[8] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};        // �����߷�
int map[8][8];        // ��ͼ
// �����ж�
int check(int x, int y)
{
	if (x>=0 && x<=7 && y>=0 && y<=7)
		return 0;
	return -1;        // ����
}
// ·�����
void printPath(int step)
{
	int count = 1;
	int i,j = 0;
	while (count < step)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (map[i][j] == count)
				{
					printf("%d,%d\n", i, j);
					goto L;
				}

			}
		}
L:
		count ++;
	}
}
// (x,y)Ϊ�������  (xEnd,yEnd)Ϊ�յ�����
int Find(int x, int y, int xEnd, int yEnd, int step)
{
	map[x][y] = step;
	if (x==xEnd && y==yEnd)
	{
		printf("step is %d\n", step);
		printPath(step);
		return 1;
	}
	for (int i = 0; i < 8; ++i)
	{
		if (check(x+move[i].x, y+move[i].y))
			if (Find(x+move[i].x, y+move[i].y, step+1) == 1)
				return 1;
		// ʧ�������
		map[x][y] = 0;
		return 0;
	}
}
