#include <iostream>
#include <vector>
/*
 * ��Զ�ģ�δ������ĵ�i
 * ��ǰ��index��[i,index)����������
 * �Ƿ���һ�����㣿
 * ���������ã�res += i - index
 * ������ʣ�� && ������δ�������i �� ��ʣ��߶ȼӵ���һ����ͬʱres++
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
