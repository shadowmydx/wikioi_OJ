#include <stdio.h>
int num[10];
int stack[10];
int top  = -1;
int length;

void printStack()
{
    int i;
    for(i = 0;i <= top;i++)
        printf("%d ",stack[i]);
}

void printFull(int start)
{
    int i;
    if(top == length - 1)
    {
        printStack();
        printf("\n");
        return;
    }
    for(i = 1;i <= length;i++)
    {
        if(num[i-1] == 0)
        {
            num[i-1] = 1;
            stack[++top] = i;
            printFull(start+1);
            top--;
            num[i-1] = 0;
        }
    }
}

int main(void)
{
    scanf("%d",&length);
    printFull(0);
    return 0;
}
