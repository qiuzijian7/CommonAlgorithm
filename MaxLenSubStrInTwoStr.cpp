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

pair<int,string> fun(const string& str1,const string& str2)
{
    vector<string> subs;
    int length1 = str1.length();
    int length2 = str2.length();
    int count =0, maxcount = 0;
    string resultstr;
    int startpos;

    for(int i =0;i<length1;i++)
    {
        for(int j=0;j<length2;j++)
        {
            count =0;
            for(int m = i,n=j;m<length1&&n<length2;)
            {
               if(str1[m++] == str2[n++])
               {
                    count++;
               }
               else
               {
                   break;
               }              
            }
            if(count > maxcount)
            {
                maxcount = count;
                resultstr = str1.substr(i,count);
            }
        }
    }
    return make_pair(maxcount,resultstr);
}

int main()
{
    //output: 5:abcda
    string str1="yyabcdabjcabceg";
    string str2="tttabcdaccc";
    pair<int,string> result = fun(str1,str2);
    cout<<result.first<<":"<< result.second<<endl;
    return 0;
}