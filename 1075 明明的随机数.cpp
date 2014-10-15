#include <stdio.h>
#include <stdlib.h>
int num[1001];
int main(void)
{
    int N;
    int tmp;
    int count = 0;
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
    {
            scanf("%d",&tmp);
            num[tmp]++;
            if(num[tmp] == 1)count++;
    }
    printf("%d\n",count);
    for(int i = 1;i < 1001;i++)
            if(num[i])printf("%d ",i);
    return 0;
}
