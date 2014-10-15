#include <iostream>
#include <algorithm>
#define MAXN 40001
using namespace std;

typedef struct node
{
    int x;
    int y;
    int value;
}node;

int prisonSet[MAXN];
int N,M;
node prison[100001];

bool cmp(const node &a,const node &b)
{
    return a.value > b.value;
}

int findRoot(int x)
{
    if(prisonSet[x] == x)
        return x;
    else return prisonSet[x] = findRoot(prisonSet[x]);
}

int main(void)
{
    cin >> N >> M;
    for(int i = 1;i <= M;i++)
        cin >> prison[i].x >> prison[i].y >> prison[i].value;
    for(int i = 1;i <= 2 * N;i++)
        prisonSet[i] = i;
    sort(prison + 1,prison + M + 1,cmp);
    for(int i = 1;i <= M;i++)
    {
        int root1 = findRoot(prison[i].x);
        int root2 = findRoot(prison[i].y);
        if(root1 == root2)
        {
            cout << prison[i].value;
            return 0;
        }
        prisonSet[root1] = findRoot(prison[i].y + N);
        prisonSet[root2] = findRoot(prison[i].x + N);
    }
    cout << 0;
    return 0;
}

