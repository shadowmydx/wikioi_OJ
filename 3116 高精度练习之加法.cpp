/*
����:wmydx@126.com
��Ŀ:p3116 �߾�����ϰ֮�ӷ�
*/

/*
//���дһ�ݿ����ύ�Ĵ��룿��P1000 A+BΪ��
#include <iostream>
using namespace std;
int main()
{
    int a, b; //��������������
    cin >> a >> b; //�ӱ�׼��������������������
    cout << a + b << endl; //�������׼�������

}
// ��ɳ����Ժ󣬵���·����ύ�����ɿ������Խ��
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
