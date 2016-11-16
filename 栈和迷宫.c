#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 200
#define MAXROW 12
#define MAXCOL 12
typedef struct
{
    int v;//竖直方向移动
    int h;//水平方向移动
} set;
typedef struct
{
    int row;
    int col;
    int dir;
} element;
int top;//栈顶位置
set move[4]= {{0,1},{1,0},{0,-1},{-1,0}}; //按照东,南,西,北的顺序进行搜索
int mark[MAXROW][MAXCOL];//用来标记位置是否已经被搜索的数组
int maze[MAXROW][MAXCOL]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};//12*12迷宫地图
element stack[MAX_STACK_SIZE];//声明栈


void push(element pos) //进栈
{
    if(top>=MAX_STACK_SIZE)
    {
        printf("stack is full.\n");
        exit(0);
    }//printf("%d\n",top);
    stack[top++]=pos;
}
element pop() //出栈
{
    if(top==-1)
    {
        printf("stack is empty\n");
        exit(0);
    }
    return stack[--top];
}
int isempty()//判断栈是否为空
{
    if(top==-1)
        return 1;
    return 0;
}
int path(int x_start,int y_start,int x_end,int y_end)
{
    int i,col,row,next_row,next_col,dir;
    element temp;
    temp.row=x_start;
    temp.col=y_start;
    temp.dir=-1;
    push(temp);//将起点进栈
    mark[x_start][y_start]=1;//标记起始位置
    while(!isempty())//如果栈不为空就一直搜索
    {
        temp=pop();
        row=temp.row;
        col=temp.col;
        dir=temp.dir+1;
        while(dir<4)
        {
            next_row=row+move[dir].v;
            next_col=col+move[dir].h;
            if(!maze[next_row][next_col]&&!mark[next_row][next_col])//如果路径为通路而且没有标记过,则继续搜索
            {
                temp.row=row;
                temp.col=col;
                temp.dir=dir;
                push(temp);
                row=next_row;
                col=next_col;
                mark[row][col]=1;
                if(row==x_end&&col==y_end)//到达终点
                {
                    for(i=0; i<top; i++)//输出栈储存的路径
                        printf("(%d,%d)",stack[i].row,stack[i].col);
                        printf("(%d,%d)\n",row,col);
                    return 1;
                }
                else
                    dir=0;
            }
            else
                dir++;
        }
    }
    return 0;
}
int
main()
{
    int x1,y1,x2,y2;//起始坐标和终点坐标
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if(path(x1,y1,x2,y2))
        printf("Yes\n");
      else

        printf("No\n");

    return 0;
}