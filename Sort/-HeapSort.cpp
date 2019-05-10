/*
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
最好是n，其他是n2，辅助空间O(1),稳定,(这个和冒泡一样)
https://www.cnblogs.com/skywang12345/p/3602162.html
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
void maxHeapDown(int* a, int start, int end)
{
    int child = start;            // 当前(current)节点的位置
    int left = 2*child + 1;        // 左(left)孩子的位置
    int tmp = a[child];            // 当前(current)节点的大小
    for (; left <= end; child=left,left=2*left+1)
    {
        // "l"是左孩子，"l+1"是右孩子
        if ( left < end && a[left] < a[left+1])
            left++;        // 左右两孩子中选择较大者，即m_heap[l+1]
        if (tmp >= a[left])
            break;        // 调整结束
        else            // 交换值
        {
            a[child] = a[left];
            a[left]= tmp;
        }
    }
}

/*
 * 堆排序(从小到大)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heapSortAsc(int* a, int n)
{
    int i,tmp;

    // 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapDown(a, i, n-1);

    // 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (i = n - 1; i > 0; i--)
    {
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
        std::swap(a[i],a[0]);
        // 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
        // 即，保证a[i-1]是a[0...i-1]中的最大值。
        maxHeapDown(a, 0, i-1);
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