#include <stdio.h>
int num[51][200001];
typedef struct hotel
{
    int color;
    int cost;
}hotel;
hotel v[200001];
int n,k;
int leastCost;
void getInput()
{
    hotel tmp;
    scanf("%d%d%d",&n,&k,&leastCost);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&tmp.color,&tmp.cost);
        v[i] = tmp;
        num[tmp.color][i] = 1;
    }
    for(int i = 0;i < k;i++)
    {
        for(int j = 1;j < n;j++)
        {
            num[i][j] += num[i][j-1];
        }
    }
}
int findThisColor(int color,int mid,int start)
{
    start --;
    int a = (start < 0 ? num[color][mid-1] : num[color][mid-1] - num[color][start]);
    int b = num[color][n-1] - num[color][mid];
    a = (a < 0 ? 0 : a);
    b = (b < 0 ? 0 : b);
    if(v[mid].color == color)
        return a * b + a + b;
    else return a * b;
}
int findTheResult()
{
    int result = 0;
    int start = 0;
    for(int i = 0;i < n;i++)
    {
        if(v[i].cost <= leastCost)
        {
            for(int j = 0;j < k;j++)
                result += findThisColor(j,i,start);
            start = i + 1;
        }
    }
    return result;
}
int main(void)
{
    int result = 0;
    getInput();
    result = findTheResult();
    printf("%d\n",result);
    return 0;
}
