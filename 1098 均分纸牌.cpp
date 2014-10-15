#include <iostream>
#include <vector>
/*
 * 最远的，未被满足的点i
 * 当前点index，[i,index)区间所需数
 * 是否能一次满足？
 * 若能且正好：res += i - index
 * 若能且剩余 && 不存在未被满足的i ： 将剩余高度加到下一个，同时res++
 */
using namespace std;

vector<int> paper;

int findRes()
{
    int sum = 0;
    int len = paper.size();
    int all;
    int res = 0;
    for (int i = 0;i < len;i++)
    {
        sum += paper[i];
    }
    all = sum / len;
    int index = -1;
    sum = 0;
    for (int i = 0;i < len;i++)
    {
        if (index == -1)
        {
            if (paper[i] < all)
            {
                index = i;
                sum += all - paper[i];
            }
            else if (paper[i] > all)
            {
                paper[i+1] += paper[i] - all;
                res ++;
            }
        }
        else
        {
            if (paper[i] > all)
            {
                if (sum <= paper[i] - all)
                {
                    res += i - index;
                    index = -1;
                    if (sum != paper[i] - all)
                    {
                        paper[i] -= sum;
                        paper[i+1] += paper[i] - all;
                        res ++;
                    }
                    sum = 0;
                }
                else
                {
                    sum -= paper[i] - all;
                }
            }
            else
            {
                sum += all - paper[i];
            }
        }
    }
    return res;
}

int main(void)
{
    int n,num;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> num;
        paper.push_back(num);
    }
    int res = findRes();
    cout << res << endl;
    return 0;
}
