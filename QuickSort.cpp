#include <iostream>
using namespace std;

void Swap(int*a ,int i,int j)
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