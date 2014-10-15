#include <iostream>
#include <string>
using namespace std;

void dealWith(string &s,int *array,int target,int size) // target表示要删成这么多的元素。size表示现有的元素
{
    int len = 0,i = 0;
    while(target != size)
    {
        s.erase(array[i] - len,1);
        i ++;
        len ++;
        size --;
    }
}

string printTheReverse(string s)
{
    string tmp;
    for(int i = s.size() - 1;i >= 0;i--)
        tmp += s[i];
    return tmp;
}

string showTheString(string s)
{
    int arrayOne[100];
    int arrayTwo[100];
    int one = -1,
        two = -1;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= 'a' && s[i] <= 'm')
            arrayOne[++one] = i;
        else arrayTwo[++two] = i;
    }
    if(two > one)
    {
        dealWith(s,arrayTwo,one,two);
    }
    else if(two < one)
    {
        dealWith(s,arrayOne,two,one);
    }
    s = printTheReverse(s);
    return s;
}

int main(void)
{
    while(true)
    {
        string tmp;
        cin >> tmp;
        cout << showTheString(tmp) << endl;
    }
    return 0;
}
