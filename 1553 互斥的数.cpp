#include <iostream>
#include <set>
using namespace std;
int N,P;
/*
    ������̰��
    ����ɾ����*it * P���Ԫ�ء���Ϊ��Ԫ��λ�ں󷽣����ܻ���һ���������������У�����ɾ��*it�����ܹ���Ҫɾ��2������ɾ��*it * P��*it��
    �޻�����

*/
int main(void)
{
    set<int> mySet;
    set<int>::iterator tmpIt;
    int tmp;
    cin >> N >> P;
    for(int i = 0;i < N;i++)
    {
    	cin >> tmp;
        mySet.insert(tmp);
    }
    for(set<int>::iterator it = mySet.begin();it != mySet.end();it++)
    {
    	tmpIt = mySet.find(*it * P);
        if(tmpIt != mySet.end())
        {
        	mySet.erase(*it * P);
        }
    }
    cout << mySet.size() << endl;
	return 0;
}
