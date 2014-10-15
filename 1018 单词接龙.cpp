/*
注意！！！！！
一个单词可以谁都不连！！！！
*/
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int isused[21];
int first[21];
string word[21];
int Link[21][21];
int number;
char start;
int forFirst = -1;

void getWord()
{
    for(int i = 0;i < number;i++)
        cin >> word[i];
    cin >> start;
}

int linkTheWord(int str1,int str2)
{
    int length1 = word[str1].size();
    int length2 = word[str2].size();
    int start = length1 - 1;
    bool flag = false;
    while(start > 0 && length1 - start < length2)
    {
        if(word[str1].substr(start) == word[str2].substr(0,length1 - start))
        {
            flag = true;
            break;
        }
        start --;
    }
    if(flag == true)
        return length2 + start;
    else return 0;
}

void init()
{
    for(int i = 0;i < number;i++)
    {
        if(word[i][0] == start)
            first[++forFirst] = i;
    }
    for(int i = 0;i < number;i++)
    {
        for(int j = 0;j < number;j++)
        {
            Link[i][j] = linkTheWord(i,j);
            if(i == j && Link[i][j] == 0)
                Link[i][j] = word[i].size(); //关键BUG
        }
    }
}

int linkTheNext(int start)
{
    int result = 0;
    int max = 0;
    for(int i = 0;i < number;i++)
    {
        if(isused[i] == 2)continue;
        if(Link[start][i] != 0)
        {
            isused[i] ++;
            result = Link[start][i] + linkTheNext(i);
            if(result != Link[start][i])
                result -= word[i].size();
            if(max < result)max = result;
            isused[i] --;
        }
    }
    return max;
}

void findTheMax()
{
    int result = 0;
    int max = 0;
    for(int i = 0;i <= forFirst;i++)
    {
        isused[first[i]] ++;
        result = linkTheNext(first[i]);
        if(result > max)max = result;
        isused[first[i]] --;
    }
    cout << max << endl;
}

int main(void)
{
    cin >> number;
    getWord();
    init();
    findTheMax();
    return 0;
}
