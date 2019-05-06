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