#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Printf(int *a,int length)
{
    for(int i = 0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

pair<int,string> fun(const string& str)
{
    vector<string> subs;
    int length = str.length();
    int count =0, maxcount = 0;
    string resultstr;
    int startpos;
    for(int i=0;i<length;i++)
    {
        subs.push_back(str.substr(i,length-i));
    }
    
    for(int i =0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            count =0;
            int curLen = j-i;
            for(int k = j;k<length;k++)
            {
                if(subs[i].substr(0,curLen) == subs[k].substr(0,curLen))
                {
                    if(curLen > maxcount)
                    {
                        maxcount = curLen;
                        resultstr = subs[i].substr(0,curLen);
                        startpos = i;
                    }
                    break;
                }
            }
           
        }
    }
    return make_pair(startpos,resultstr);
}

int main()
{
    //output: 2:abc
    string str = "yyabcdabjcabceg";
    pair<int,string> result = fun(str);
    cout<<result.first<<":"<< result.second<<endl;
    return 0;
}