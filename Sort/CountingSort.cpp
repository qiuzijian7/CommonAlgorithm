/*
计数排序不是基于比较的排序算法，
其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数
都是 n+k ,稳定
*/

#include <iostream>
using namespace std;

void Printf(int *a,int length)
{
     for(int i = 0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void CountingSort(int* a , int length)
{
    int* tmp = new int[length];
    for(int i=0;i<length;i++)
    {
       tmp[a[i]]++;
    }
    for(int j =0;j<length;j++)
    {
        if(tmp[j]>0)
        {
            a[j] = j;
        }
    }
    delete[] tmp;
}

int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    CountingSort(str,length);
    Printf(str,length);
    return 0;
}