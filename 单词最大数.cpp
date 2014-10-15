#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*  无数WA，全部都在于countWord的实现错误。
    见代码体
*/
string input;
vector<string> dic;
int p,k,s;
int dp[201][201]; //以i为终点，划分j次
int dp2[201][201];

void initDP()
{
    for(int i = 0;i < 201;i++)
        for(int j = 0;j < 201;j++)
        {
            dp2[i][j] = -1;
            dp[i][j] = -1;
        }
}

int countWord(int start,int end)
{
    if(dp2[start][end] != -1)
        return dp2[start][end];
    string tmp = input.substr(start,end - start + 1);
    string tmp2;
    int a[201];
    int result = 0;
    for(int i = 0;i < tmp.size();i++)
        a[i] = 0;
    for(int i = 0;i < dic.size();i++)
    {
        tmp2 = tmp; //错误1：由于在tmp的基础上对while循环体操作，导致tmp2保持不变，进入死循环
        int pos = 0;//错误2：更新字符串后，返回的是新字符串的位置，而需要的是位置在旧字符串中的位置
        int tmp1 = tmp2.find(dic[i]);
        while(tmp1 != string::npos)
        {
            a[tmp1+pos] = 1;
            pos += tmp1 + 1;
            tmp2 = tmp2.substr(tmp1+1);//错误3：直接剔除特定字符串，使得失去勘察aaaaa此类连续字符串的机会
            tmp1 = tmp2.find(dic[i]);
        }
    }
    for(int i = 0;i < tmp.size();i++)
        if(a[i] == 1)
            result ++;
    return dp2[start][end] = result;
}

int findTheResult(int end,int div)
{
    if(dp[end][div] != -1)
        return dp[end][div];
    if(div == 1)
        return countWord(0,end);
    int result = 0;
    int max = 0;
    for(int i = end - 1;i >= 0;i--)
    {
        if(i + 1 >= div - 1)
        {
            result = countWord(i+1,end) + findTheResult(i,div-1);
            if(result > max)max = result;
        }
    }
    return dp[end][div] = max;
}

void printAnswer()
{
    int result = findTheResult(input.size() - 1,k);
    cout << result << endl;
}

int main(void)
{
    /*
    string tmp;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> p >> k;
        for(int i = 0;i < p;i++)
        {
            cin >> tmp;
            input += tmp;
        }
        cin >> s;
        for(int i = 0;i < s;i++)
        {
            cin >> tmp;
            dic.push_back(tmp);
        }
        initDP();
        printAnswer();
        dic.clear();
        input.clear();
    }*/
    int a = (1 << 32) - 3;
    cout <<(a & (-a))<< endl;
    return 0;
}
