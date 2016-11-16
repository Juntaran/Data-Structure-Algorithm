#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 200
#define MAXROW 12
#define MAXCOL 12
typedef struct
{
    int v;//��ֱ�����ƶ�
    int h;//ˮƽ�����ƶ�
} set;
typedef struct
{
    int row;
    int col;
    int dir;
} element;
int top;//ջ��λ��
set move[4]= {{0,1},{1,0},{0,-1},{-1,0}}; //���ն�,��,��,����˳���������
int mark[MAXROW][MAXCOL];//�������λ���Ƿ��Ѿ�������������
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
};//12*12�Թ���ͼ
element stack[MAX_STACK_SIZE];//����ջ


void push(element pos) //��ջ
{
    if(top>=MAX_STACK_SIZE)
    {
        printf("stack is full.\n");
        exit(0);
    }//printf("%d\n",top);
    stack[top++]=pos;
}
element pop() //��ջ
{
    if(top==-1)
    {
        printf("stack is empty\n");
        exit(0);
    }
    return stack[--top];
}
int isempty()//�ж�ջ�Ƿ�Ϊ��
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
    push(temp);//������ջ
    mark[x_start][y_start]=1;//�����ʼλ��
    while(!isempty())//���ջ��Ϊ�վ�һֱ����
    {
        temp=pop();
        row=temp.row;
        col=temp.col;
        dir=temp.dir+1;
        while(dir<4)
        {
            next_row=row+move[dir].v;
            next_col=col+move[dir].h;
            if(!maze[next_row][next_col]&&!mark[next_row][next_col])//���·��Ϊͨ·����û�б�ǹ�,���������
            {
                temp.row=row;
                temp.col=col;
                temp.dir=dir;
                push(temp);
                row=next_row;
                col=next_col;
                mark[row][col]=1;
                if(row==x_end&&col==y_end)//�����յ�
                {
                    for(i=0; i<top; i++)//���ջ�����·��
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
    int x1,y1,x2,y2;//��ʼ������յ�����
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if(path(x1,y1,x2,y2))
        printf("Yes\n");
      else

        printf("No\n");

    return 0;
}