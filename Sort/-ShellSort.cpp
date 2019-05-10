/*
1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
平均：n1.3，最坏n2，最好n，辅助空间O(1),不稳
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

void ShellSort(int* a , int length)
{
    int gap = 1;
    while(gap < length /3)
    {
        gap = gap*3+1;
    }
    for(gap;gap>0;gap/=3)
    {
        cout<<"gap:"<<gap<<endl;
        for(int i=gap;i<length;i++)
        {
            int temp = a[i];
            int j;
            for(j = i-gap;j>=0 && a[j]>temp;j-=gap)
            {
                a[j+gap] = a[j];
            }
            a[j+gap] = temp;
        }      
    }
}


int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    ShellSort(str,length);
    Printf(str,length);
    return 0;
}