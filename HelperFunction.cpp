#include <iostream>
using namespace std;

void swap(int*a ,int i,int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] =tmp;
}

void Printf(int *a,int length)
{
    for(int i = 0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    return 0;
}