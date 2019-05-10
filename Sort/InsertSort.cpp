/*
插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。
它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
最好是n，其他是n2，辅助空间O(1),稳定,(这个和冒泡一样)
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

void InsertSort(int* a , int length)
{
    for(int i=1;i<length;i++)
    {
        int preIndex = i-1;
        for(int j =i;j>0;j--)
        {
            if(a[j]<a[preIndex])
            {
                std::swap(a[j],a[preIndex]);
                preIndex --;
            }
            else
            {
                break;
            }
            
        }
    }
}


int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    InsertSort(str,length);
    Printf(str,length);
    return 0;
}