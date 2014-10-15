#include <iostream>
#include <set>
using namespace std;
int N,P;
/*
    方法：贪心
    首先删除掉*it * P这个元素。因为该元素位于后方，可能还有一个互斥数，而若有，加上删除*it，则总共需要删除2个。而删除*it * P，*it已
    无互斥数

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
