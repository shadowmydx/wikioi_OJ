#include <stdio.h>
#include <stdlib.h>
int result[30][30];
int horse[30][30];
int n,m;
int horsex,horsey;
void initial()
{
     horse[horsex][horsey] = 1;
     if(horsex - 1 >= 0 && horsey - 2 >= 0)horse[horsex-1][horsey-2] = 1;
     if(horsex - 2 >= 0 && horsey - 1 >= 0)horse[horsex-2][horsey-1] = 1;
     if(horsex - 2 >= 0 && horsey + 1 <= m)horse[horsex-2][horsey+1] = 1;
     if(horsex - 1 >= 0 && horsey + 2 <= m)horse[horsex-1][horsey+2] = 1;
     if(horsex + 1 <= n && horsey - 2 >= 0)horse[horsex+1][horsey-2] = 1;
     if(horsex + 2 <= n && horsey - 1 >= 0)horse[horsex+2][horsey-1] = 1;
     if(horsex + 2 <= n && horsey + 1 <= m)horse[horsex+2][horsey+1] = 1;
     if(horsex + 1 <= n && horsey + 2 <= m)horse[horsex+1][horsey+2] = 1;
}
int find(int startx,int starty)
{
    if(horse[startx][starty])return 0;
    if(startx == n - 1 && starty == m)return 1;
    if(startx == n && starty == m - 1)return 1;
    if(result[startx][starty])return result[startx][starty];
    int result1 = 0;
    int result2 = 0;
    if(startx + 1 <= n)
    {
        if(!horse[startx+1][starty])result1 = find(startx + 1,starty);
        result[startx+1][starty] = result1;
    }
    if(starty + 1 <= m)
    {
        if(!horse[startx][starty+1])result2 = find(startx,starty + 1);
        result[startx][starty+1] = result2;
    }
    return result[startx][starty] = result1 + result2;
}
int main(void)
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&horsex,&horsey);
    initial();
    printf("%d\n",find(0,0));
    system("pause");
    return 0;                    
}
