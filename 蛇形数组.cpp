#include <stdio.h>
#include <stdlib.h>
int a[200][200];
struct point 
{
       int x;
       int y;
};
int main(void)
{
    int n;
    int dir = 0;
    int step = 1;
    int count = 2;
    int flag = 0;
    int end = 0;
    int result = 0;
    point start;
    scanf("%d",&n);
    start.x = n / 2;
    start.y = n / 2;
    a[start.x][start.y] = 1;
    while(1)
    {
                switch(dir)
                {
                           case 0 : for(int i = 0;i < step;i++)
                                    {
                                            start.y++;
                                            a[start.x][start.y] = count++;        
                                    } 
                                    dir = 1;
                                    if(count >= n * n + 1)end = 1; 
                                    flag ++;
                                    if(flag == 2)
                                    {
                                            flag = 0;
                                            step ++;
                                    }
                                    break;
                           case 1 : for(int i = 0;i < step;i++)
                                    {
                                            start.x--;
                                            a[start.x][start.y] = count++;        
                                    }
                                    dir = 2;
                                    if(count >= n * n + 1)end = 1;
                                    flag ++;
                                    if(flag == 2)
                                    {
                                            flag = 0;
                                            step ++;
                                    }
                                    break;
                           case 2 : for(int i = 0;i < step;i++)
                                    {
                                            start.y--;
                                            a[start.x][start.y] = count++;        
                                    }
                                    dir = 3;
                                    flag ++;
                                    if(count >= n * n + 1)end = 1;
                                    if(flag == 2)
                                    {
                                            flag = 0;
                                            step ++;
                                    }
                                    break;
                           case 3 : for(int i = 0;i < step;i++)
                                    {
                                            start.x++;
                                            a[start.x][start.y] = count++;        
                                    }
                                    dir = 0;
                                    flag ++;
                                    if(count >= n * n + 1)end = 1;
                                    if(flag == 2)
                                    {
                                            flag = 0;
                                            step ++;
                                    }
                                    break;
                                             
                }      
                if(end)break;  
    }
    for(int i = 0;i < n;i++)
    {
            for(int j = 0;j < n;j++)
            {
                    if(i == j)result += a[i][j];
                    if(i + j == n - 1)result += a[i][j];
                    printf("%d ",a[i][j]);
            }
            printf("\n");
    }
    result -= a[n/2][n/2];
    printf("%d\n",result);
    system("pause");
    return 0;    
}
