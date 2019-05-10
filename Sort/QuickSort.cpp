
/*
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，
则可分别对这两部分记录继续进行排序，以达到整个序列有序。
都是nlogn，最坏是n2,不稳定,
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

int Partition(int* a, int low, int high) {
    int i     = low;
    int pivot = high;
    int value = a[high];
    for (int j = low; j < high; ++j)
        if (a[j] <= value) 
            std::swap(a[j], a[i++]);
    std::swap(a[i], a[high]);
    return i;
}
void QuickSort(int* a ,int low,int high)
{
    if(low<high)
    {
        int pivot = Partition(a,low,high);
        QuickSort(a,low,pivot-1);
        QuickSort(a,pivot+1,high);
    }
}

int main()
{
    int str[] = {5,4,8,7,9,6,3,2,1,0};
    int length = sizeof(str)/sizeof(int);
    //BubbleSort(str,length);
    QuickSort(str,0,length-1);
    Printf(str,length);
    return 0;
}