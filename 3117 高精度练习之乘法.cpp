/*
作者:wmydx@126.com
题目:p3117 高精度练习之乘法
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

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size())
            return multiply(num2,num1); // always asume num1 is bigger than num2.
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size();
        int len2 = num2.size();
        string res(len1 + len2,'0');
        int resptr = res.size() - 1;
        int carry  = 0; // 进位
        for (int i = len2 - 1;i >= 0;i--)
        {
            int now = resptr;
            for (int j = len1 - 1;j >= 0;j--)
            {
                int tmp = char2int(res[now]) + char2int(num1[j]) * char2int(num2[i]) + carry;
                if (tmp >= 10)
                    carry = tmp / 10;
                else
                    carry = 0;
                tmp = tmp % 10;
                res[now] = tmp + '0';
                now --;
            }
            if (carry)
            {
                int tmp = char2int(res[now]) + carry;
                res[now] = (tmp % 10) + '0';
                carry /= 10;
            }
            resptr --;
        }
        int start = 0;
        while (res[start] == '0')
            start ++;
        return res.substr(start);
    }

    int char2int(char num)
    {
        return num - '0';
    }
};

int main(void)
{
    string a,b;
    Solution p;
    cin >> a >> b;
    cout << p.multiply(a,b) << endl;
    return 0;
}
