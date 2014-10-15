#include <iostream>
#include <tr1/unordered_set>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
using namespace std::tr1;

struct node
{
    string now;
    int len;
};

unordered_set<string> dict;
vector<string> from;
vector<string> to;
queue<node> myque;

void expendNode(node &tmp)
{
    unordered_set<string> :: iterator it;
    node here;
    here.len = tmp.len + 1;
    int len1 = from.size();
    for (int i = 0;i < len1;i++)
    {
        int index = -1;
        while ((index = tmp.now.find(from[i],index + 1)) != string::npos)
        {
            string build = tmp.now.substr(0,index) + to[i] + tmp.now.substr(index + from[i].size());
            it = dict.find(build);
            if (it == dict.end())
            {
                dict.insert(build);
                here.now = build; // 判重才入队
                myque.push(here);
            }

        }
    }
}

int findRes(string &ori,string &tar)
{
    node tmp;
    tmp.now = ori;
    tmp.len = 0;
    myque.push(tmp);
    dict.insert(ori);
    while (!myque.empty())
    {
        tmp = myque.front();
        if (tmp.len > 10)
            return 11;
        if (tmp.now == tar)
        {
            return tmp.len;
        }
        expendNode(tmp);
        myque.pop();
    }
    return 11;
}

int main(void)
{
    string ori;
    string tar;
    string tmp1,tmp2;
    cin >> ori >> tar;
    while (cin >> tmp1 >> tmp2)
    {
        from.push_back(tmp1);
        to.push_back(tmp2);
    }
    int minLen = findRes(ori,tar);
    if (minLen > 10)
        cout << "NO ANSWER!" << endl;
    else
        cout << minLen << endl;
    return 0;
}
