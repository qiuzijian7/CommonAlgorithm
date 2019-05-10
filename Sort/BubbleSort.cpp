/*
冒泡排序是一种简单的排序算法。
它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。
走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 
最好是n，其他是n2，辅助空间O(1),稳定
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

void BubbleSort(int* a , int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j =0;j<length-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a,j,j+1);
            }
        }
    }
}
void BubbleSortOpt(int* a,int length)
{
    for(int i=0;i<length;i++)
    {
        bool bSwapped =false;
        for(int j =0;j<length-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a,j,j+1);
                bSwapped =true;
            }
        }
        if(!bSwapped)
            break;
    }
}

int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    BubbleSortOpt(str,length);
    Printf(str,length);
    return 0;
}