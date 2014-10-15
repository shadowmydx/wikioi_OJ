#include <stdio.h>
int k;
double caculate(int i)
{
    return 1/(double)i;
}
int main(void)
{
    double Sn = 1;
    int i = 1;
    scanf("%d",&k);
    while(Sn <= k)
        Sn += caculate(++i);
    printf("%d\n",i);
    return 0;
}
