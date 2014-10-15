	#include <string>
	#include <vector>
	#include <iostream>
	using std::vector;
	using std::string;
	using std::cout;
	using std::endl;
	int main(void)
	{
	    vector<string> keyWord;
        string keyword[31] = { "char","short","int","unsigned",
                              "long","float","double","struct",
                              "union","void","enum","signed",
                              "const","volatile","typedef","auto",
                              "register","static","extern","break",
                              "case","continue","default","do",
                              "else","for","goto","if",
                              "return","switch","while"
                            };
        for(int i = 0;i < 31;i++)
        {
            keyWord.push_back(keyword[i]);
        }
        for(int i = 0;i < keyWord.size();i++)
            cout << keyWord[i] << endl;
	}
