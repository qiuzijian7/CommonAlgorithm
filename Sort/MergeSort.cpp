/*
归并排序是建立在归并操作上的一种有效的排序算法。
该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
若将两个有序表合并成一个有序表，称为2-路归并。
都是nlogn，，辅助空间O(n),稳定,
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
void Merge(int* a , int start,int middle ,int end)
{
    int tmpCount = end - start +1;
    int * tmp = new int[tmpCount];

    int i =0;
    int left = start;
    int right = middle +1;

    while(left<=middle && right<=end)
    {
        tmp[i++] = a[left]<=a[right]?a[left++]:a[right++];
    }
    while(left<=middle)
    {
        tmp[i++] = a[left++];
    }
    while(right<=end)
    {
        tmp[i++] = a[right++];
    }
    for(int j = 0;j<tmpCount;j++)
    {
        a[start+j] = tmp[j];
    }
    delete[] tmp;
}

void MergeSort(int* a , int start,int end)
{
    if( start < end)
    {      
        int middle = (start +end )/2;
        MergeSort(a,start,middle);
        MergeSort(a,middle+1,end);
        Merge(a,start,middle, end);
    }

}


int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    MergeSort(str,0,length-1);
    Printf(str,length);
    return 0;
}