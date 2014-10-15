/*
作者:wmydx@126.com
题目:p3116 高精度练习之加法
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


int toNum(char a)
{
    return a - '0';
}

char toChar(int a)
{
    return a + '0';
}

string addNum(string &a,string &b)
{
    int len1 = a.size();
    int len2 = b.size();
    if (len1 < len2)
        return addNum(b,a); // always assume a is bigger than b.
    int i = len1 - 1;
    int j = len2 - 1;
    string res;
    int flag = 0;
    int num;
    while (j >= 0)
    {
        num = toNum(a[i]) + toNum(b[j]) + flag;
        if (num >= 10)
            flag = 1;
        else
            flag = 0;
        num %= 10;
        res = res + toChar(num);
        j --;
        i --;
    }
    while (flag)
    {
        num = i >= 0 ? toNum(a[i]) + flag : flag;
        flag = num >= 10 ? 1 : 0;
        num %= 10;
        res = res + toChar(num);
        i --;
    }
    while (i >= 0)
    {
        res = res + a[i];
        i --;
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(void)
{
    string a,b;
    cin >> a >> b;
    cout << addNum(a,b) << endl;
    return 0;
}
