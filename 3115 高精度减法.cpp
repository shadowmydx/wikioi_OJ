/*
作者:wmydx@126.com
题目:p3115 高精度练习之减法
*/

/*
//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
using namespace std;
int main()
{
    int a, b; //定义两个变量名
    cin >> a >> b; //从标准输入流中输入两个整数
    cout << a + b << endl; //输出到标准输出流中

}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isSmall(string &a,string &b)
{
    int len1 = a.size();
    int len2 = b.size();
    int i,j;
    i = j = 0;
    if (len1 < len2)
        return true;
    else if (len1 > len2)
        return false;
    else
    {
        while (i < len1 && a[i] == b[j])
        {
            i ++,j ++;
        }
        if (i < len1)
        {
            return a[i] < b[j];
        }
    }
    return false;
}

int toNum(char a)
{
    return a - '0';
}

char toChar(int a)
{
    return a + '0';
}

string subNum(string &a,string &b) // a - b, a is bigger than b
{
    int len1 = a.size();
    int len2 = b.size();
    int i = len1 - 1;
    int j = len2 - 1;
    string res;
    while (j >= 0)
    {
        int num1 = toNum(a[i]);
        int num2 = toNum(b[j]);
        if (num1 < num2)
        {
            num1 += 10;
            int tmp = i - 1;
            while (a[tmp] == '0')
            {
                a[tmp] = '9';
                tmp --;
            }
            a[tmp] --;
        }
        res = res + toChar(num1 - num2);
        i --,j --;
    }
    int start = 0;
    while (a[start] == '0')
        start ++;
    while (i >= start)
    {
        res = res + a[i];
        i --;
    }
    reverse(res.begin(),res.end());
    start = 0;
    while (start < res.size() && res[start] == '0')
        start ++;
    if (start == res.size())
        return "0";
    return res.substr(start);
}

int main(void)
{
    string a,b;
    string tmp;
    int flag = 0;
    cin >> a >> b;
    if (isSmall(a,b)) // always assume abs(a) >= abs(b)
    {
        tmp = subNum(b,a);
        flag = 1;
    }
    else
        tmp = subNum(a,b);
    if (flag)
        cout << "-" << tmp << endl;
    else
        cout << tmp << endl;
    return 0;
}
