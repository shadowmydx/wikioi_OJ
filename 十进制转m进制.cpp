#include <stdio.h>
#include <stdlib.h>
char num[] = "ABCDEF";
void change(int n,int m)
{
     int top = -1;
     char re[100];
     while(n)
     {
             if(n % m >= 10)
             {
                  re[++top] = num[n%m - 10];
             }
             else
             {
                 re[++top] = n % m + 48;
             }
             n /= m;
     } 
     for(int i = top;i >= 0;i--)
             printf("%c",re[i]);    
}
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    change(n,m);
    return 0;
}
