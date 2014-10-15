#include <iostream>
#include <fstream>
using namespace std;
int map[10][10];
int point[10];
int number;
int result = 0;
int now = 0;
ifstream in("1116.txt");
/*
DFS的思路：
1、不是说是图，就是遍历图。
2、本处以点的着色为遍历对象，图为是否可以使用某颜色的参考
*/
void test()
{
    for(int i = 0;i < number;i++)
    {
        cout << "point[" << i << "]" << " = " << point[i] << " ";
    }
    cout << endl;
}

void getInput()
{
    for(int i = 0;i < number;i++)
    {
        for(int j = 0;j < number;j++)
            in >> map[i][j];
    }
}

int canSelect(int start,int *color)
{
    int result = 4;
    for(int i = 0;i < number;i++)
    {
        if(map[start][i] == 1)
        {
            if(point[i] != 0)
            {
                color[point[i]-1] = 0;
                result --;
            }
        }
    }
    return result;
}

void DFS(int start)
{
    if(start >= number)
    {
        result ++;
        //test();
        return;
    }
    int flag;
    int color[4] = {1,1,1,1};
    flag = canSelect(start,color);
    if(flag == 0)
        return;
    for(int i = 0;i < 4;i++)
    {
        if(color[i] == 1)
        {
            point[start] = i + 1;
            DFS(start + 1);
        }
        point[start] = 0;
    }

}

int main(void)
{
    in >> number;
    getInput();
    DFS(0);
    cout << result << endl;
    return 0;
}
