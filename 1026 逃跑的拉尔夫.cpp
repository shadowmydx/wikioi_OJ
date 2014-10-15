#include <stdio.h>
#include <stdlib.h>
char map[51][51];
int dic[2001];
int r,c; // r行c列
int length;
int flag[51][51][2001];
/*
注意：每个方向至少走一次！
注意：可以记忆化搜索，也就是动态规划
      flag[x]
*/

void test()
{
    for(int i = 0;i < length;i++)
        printf("%d ",dic[i]);
    printf("\n");
}

void initMap(int *start,int *end)
{
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            map[i][j] = getchar();
            if(map[i][j] == '*')
            {
                *start = i;
                *end = j;
                map[i][j] = '.';
            }
        }
        getchar();
    }
}

void printFinal()
{
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
}

void initDic()
{
    char c[10];
    for(int i = 0;i < length;i++)
    {
        scanf("%s",c);
        switch(c[0])
        {
            case 'E' : dic[i] = 0;
                       break;
            case 'S' : dic[i] = 1;
                       break;
            case 'W' : dic[i] = 2;
                       break;
            case 'N' : dic[i] = 3;
                       break;
        }
    }
}

bool judgeCanGo(int x,int y,int dic)
{
    switch(dic)
    {
        case 0 : y ++;
                 break;
        case 1 : x ++;
                 break;
        case 2 : y --;
                 break;
        case 3 : x --;
                 break;
    }
    return x >=0 && x < r && y >= 0 && y < c && map[x][y] != 'X';
}


int moveToX(int x,int dic)
{
    if(dic == 2 || dic == 0)
        return x;
    return dic == 1 ? x + 1 : x - 1;
}

int moveToY(int y,int dic)
{
    if(dic == 1 || dic == 3)
        return y;
    return dic == 0 ? y + 1 : y - 1;
}

void findTheWay(int pos,int x,int y) //POS 为要执行的指令
{
    int tmpx,tmpy;
    if(flag[x][y][pos] == 1)
            return;
    flag[x][y][pos] = 1;
    if(pos == length - 1)
    {

        if(judgeCanGo(x,y,dic[pos]))
        {
            tmpx = moveToX(x,dic[pos]);
            tmpy = moveToY(y,dic[pos]);
            //printf("tmpx = %d,tmpy = %d,x = %d,y = %d,pos = %d\n",tmpx,tmpy,x,y,pos);
            //system("pause");
            map[tmpx][tmpy] = '*';
            flag[tmpx][tmpy][pos] = 1;
            findTheWay(pos,tmpx,tmpy);
        }
        else return;
    }
    else
    {
        if(judgeCanGo(x,y,dic[pos]))
        {
            tmpx = moveToX(x,dic[pos]);
            tmpy = moveToY(y,dic[pos]);
            //printf("tmpx = %d,tmpy = %d,x = %d,y = %d,pos = %d\n",tmpx,tmpy,x,y,pos);
            //system("pause");
            findTheWay(pos,tmpx,tmpy);
            if(judgeCanGo(tmpx,tmpy,dic[pos+1]))
            {
                findTheWay(pos+1,tmpx,tmpy);
            }
        }
    }
}

void initFirstStep(int *start,int *end)
{
    if(judgeCanGo(*start,*end,dic[0]))
    {
            *start = moveToX(*start,dic[0]);
            *end = moveToY(*end,dic[0]);
    }
}

int main(void)
{
    int start,end;
    scanf("%d%d",&r,&c); // 注意此处有一个回车
    getchar();
    initMap(&start,&end);
    scanf("%d",&length);
    initDic();
    findTheWay(0,start,end);
    printFinal();
    return 0;
}
