#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct line
{
    int start;
    int fin;
};

vector<line> total;

bool operator < (const line &a1,const line &a2)
{
    return a1.start < a2.start;
}

int main(void)
{
    int n;
    line tmp;
    int dp[102] = {0};
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> tmp.start;
        cin >> tmp.fin;
        if (tmp.start > tmp.fin)
        {
            int p = tmp.start;
            tmp.start = tmp.fin;
            tmp.fin = p;
        }
        total.push_back(tmp);
    }
    sort(total.begin(),total.end());
    dp[0] = 1;
    for (int i = 1;i < n;i ++)
    {
        int sum = 0;
        for (int j = i - 1;j >= 0;j --)
        {
            if (total[j].fin <= total[i].start)
            {
                sum = dp[j];
                break;
            }
        }
        dp[i] = sum + 1;
    }
    int max = 0;
    for (int i = 0;i < n;i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }
    cout << max << endl;
    return 0;
}
