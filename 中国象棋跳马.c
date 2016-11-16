// 1. 中国象棋中 马走日可以走到任意点 所以第一个问题无需判定
// 2. 可以使用回溯法寻找路径

struct Point
{
	int x;
	int y;
};
Point move[8] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};        // 所有走法
int map[8][8];        // 地图
// 回溯判定
int check(int x, int y)
{
	if (x>=0 && x<=7 && y>=0 && y<=7)
		return 0;
	return -1;        // 出界
}
// 路径输出
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
// (x,y)为起点坐标  (xEnd,yEnd)为终点坐标
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
		// 失败则回溯
		map[x][y] = 0;
		return 0;
	}
}
