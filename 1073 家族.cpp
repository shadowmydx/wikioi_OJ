#include <iostream>
using namespace std;

int n,m,p;
int relation[5003];

int findRoot(int x)
{
    if(relation[x] == x)
        return x;
    else return relation[x] = findRoot(relation[x]);
}

int main(void)
{
    cin >> n >> m >> p;
    for(int i = 1;i <= n;i++)
        relation[i] = i;
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        int root1 = findRoot(x);
        int root2 = findRoot(y);
        relation[root2] = root1;
    }
    for(int i = 0;i < p;i++)
    {
        int x,y;
        cin >> x >> y;
        int root1 = findRoot(x);
        int root2 = findRoot(y);
        if(root1 == root2)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
