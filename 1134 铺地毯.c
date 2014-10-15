#include <stdio.h>
/*关键在于从最后一块地毯开始搜索*/
typedef struct Range
{
    int x1;
    int x2;
    int y1;
    int y2;
}Range;
Range num[10000];
int n;
void getInput(int i)
{
    int x,y,width,height;
    scanf("%d%d%d%d",&x,&y,&width,&height);
    num[i].x1 = x;
    num[i].x2 = x + width;
    num[i].y1 = y;
    num[i].y2 = y + height;
}
int isInHere(int x,int y,int i)
{
    if(x >= num[i].x1 && x <= num[i].x2 && y >= num[i].y1 && y <= num[i].y2)
        return 1;
    else return 0;
}
void findTheResult(int x,int y)
{
    int i;
    for(i = n-1;i >= 0;i--)
    {
        if(isInHere(x,y,i))
        {
            printf("%d\n",i+1);
            return;
        }
    }
    printf("%d\n",-1);
    return;
}
int main(void)
{
    int x,y,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
        getInput(i);
    scanf("%d%d",&x,&y);
    findTheResult(x,y);
    return 0;
}
