#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char num[] = "ABCDEF";
int change(char *n,int m)
{
        int length = strlen(n);
        int result = 0;
        int step = 1;
        for(int i = length - 1;i >= 0;i--)
        {
                if(n[i] > 57) 
                {
                        result += (n[i] - 55) * step;
                }      
                else
                {
                    result += (n[i] - 48) * step;
                }
                step *= m;
        }
        return result;
}
int main(void)
{
    char n[200];
    int m;
    scanf("%s%d",n,&m);
    printf("%d\n",change(n,m));
    system("pause");
    return 0;
}
