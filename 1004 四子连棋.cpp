#include <tr1/unordered_set>
#include <iostream>
#include <string>
#include <queue>
#define B 1
#define W 2
#define O 0
using namespace std;
using namespace std::tr1;

struct dep
{
    long long tar;
    int res;
};

unordered_set<long long> dict; // 标记已经存在的状态
long long val[16]; // 用来把局面换算为数字
queue<dep> myque;
char node[4][4];

void init()
{
    val[15] = 1;
    for (int i = 14;i >= 0;i --)
    {
        val[i] = 1;
        val[i] = val[i+1] * 10;
    }
}

void fillNode(long long tar)
{
    long long tmp = tar;
    for (int i = 3;i >= 0;i --)
        for (int j = 3;j >= 0;j --)
        {
            node[i][j] = tmp % 10;
            tmp /= 10;
        }
}

bool isTarget(long long tar)
{
    int flag;
    fillNode(tar);
    for (int i = 0;i < 4;i++) // check row
    {
        flag = node[i][0];
        if (flag == 0)
            continue;
        for (int j = 1;j < 4;j++)
        {
            if (node[i][j] != flag)
                break;
            if (j == 3)
                return true;
        }
    }
    for (int i = 0;i < 4;i++) // check col
    {
        flag = node[0][i];
        if (flag == 0)
            continue;
        for (int j = 1;j < 4;j++)
        {
            if (node[j][i] != flag)
                break;
            if (j == 3)
                return true;
        }
    }
    flag = node[0][0];
    if (flag)
        for (int i = 0,j = 0;i < 4;i++,j++)
        {
            if (node[i][j] != flag)
                break;
            if (i == 3)
                return true;
        }
    flag = node[0][3];
    if (flag)
        for (int i = 0,j = 3;i < 4;i++,j--)
        {
            if (node[i][j] != flag)
                break;
            if (i == 3)
                return true;
        }
    return false;
}

void clearNode()
{
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
            node[i][j] = 0;
}

void expendNode(long long target,int depth)
{
    dep tmp;
    tmp.res = depth + 1;
    int x,y;
    int zero = 0;
    int turn = B;
    if (target & 1)
    {
        turn = W; // 上一轮若是B，则这一轮到W
        zero = 0;
    }
    else
    {
        turn = B;
        zero = 1;
    }
    target /= 10;
    long long now = target;
    unordered_set<long long> :: iterator it;
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
        {
            if (node[i][j] == 0)
            {
                now = target;
                x = i;
                y = j;
                if (x - 1 >= 0 && node[x-1][y] == turn)
                {
                    now = now - val[4 * (x - 1) + y] * node[x-1][y]; // set node[x-1][y] to 0.
                    now = now + val[4 * x + y] * node[x-1][y]; // set node[x][y] to node[x-1][y].
                    now = now * 10 + zero;
                    it = dict.find(now);
                    if (it == dict.end())
                    {
                        dict.insert(now);
                        tmp.tar = now;
                        myque.push(tmp);
                    }

                }
                now = target;
                if (x + 1 < 4 && node[x+1][y] == turn)
                {
                    now = now - val[4 * (x + 1) + y] * node[x+1][y];
                    now = now + val[4 * x + y] * node[x+1][y];
                    now = now * 10 + zero;
                    it = dict.find(now);
                    if (it == dict.end())
                    {
                        dict.insert(now);
                        tmp.tar = now;
                        myque.push(tmp);
                    }
                }
                now = target;
                if (y - 1 >= 0 && node[x][y-1] == turn)
                {
                    now = now - val[4 * x + y - 1] * node[x][y-1]; // set node[x-1][y] to 0.
                    now = now + val[4 * x + y] * node[x][y-1]; // set node[x][y] to node[x-1][y].
                    now = now * 10 + zero;
                    it = dict.find(now);
                    if (it == dict.end())
                    {
                        dict.insert(now);
                        tmp.tar = now;
                        myque.push(tmp);
                    }
                }
                now = target;
                if (y + 1 < 4 && node[x][y+1] == turn)
                {
                    now = now - val[4 * x + y + 1] * node[x][y+1];
                    now = now + val[4 * x + y] * node[x][y+1];
                    now = now * 10 + zero;
                    it = dict.find(now);
                    if (it == dict.end())
                    {
                        dict.insert(now);
                        tmp.tar = now;
                        myque.push(tmp);
                    }
                }
            }
        }
}

int findRes(long long start)
{
    int res = 0;
    dep now;
    now.res = res;
    now.tar = start * 10 + 1;
    dict.insert(now.tar); // 轮到B，则为1.轮到W，则为0
    myque.push(now);
    now.tar = start * 10;
    dict.insert(now.tar);
    myque.push(now);
    while (!myque.empty())
    {
        dep tmp = myque.front();
        if (isTarget(tmp.tar / 10))
        { // always assume when isTarget method done, node is the node to expend.
            return tmp.res;
        }
        expendNode(tmp.tar,tmp.res);
        myque.pop();
    }
}

int main(void)
{
    string a,b,c,d;
    string res;
    cin >> a >> b >> c >> d;
    res = a + b + c + d;
    init();
    long long start = 0;
    for (int i = 0;i < 16;i++)
    {
        switch(res[i])
        {
            case 'B' : start = start + val[i] * B;
                       break;
            case 'W' : start = start + val[i] * W;
                       break;
            case 'O' : break;
        }
    }
    int minStep = findRes(start);
    cout << minStep << endl;
    return 0;
}
