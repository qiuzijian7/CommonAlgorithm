/*
选择排序(Selection-sort)是一种简单直观的排序算法。
它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。 
都是n2，不稳定，辅助是O(1)
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

void SelectionSort(int*a , int length)
{
    for(int i=0;i<length;i++)
    {
        int minValue = a[i];
        int minIndex = i;
        int j=i+1;
        for(;j<length;j++)
        {
            if(a[j]<minValue)
            {
                minIndex = j;
                minValue = a[j];
            }
        }
        std::swap(a[i],a[minIndex]);
    }
}

int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    SelectionSort(str,length);
    Printf(str,length);
    return 0;
}