#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    vector<int> arr;
    int N = 0;

private:
    void exch(int i,int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void swim(int k)
    {
        while(k > 1 && arr[k/2] < arr[k])
        {
            exch(k/2,k);
            k = k /2;
        }
    }

    void sink(int k)
    {
        while(2 * k <= N)
        {
            int j = 2*k;
            if(j < N && (arr[j] < arr[j+1]))
                j++;
            if(arr[k] > arr[j])
                break;
            exch(k,j);
            k = j;
        }
    }

public:
    MaxHeap(int n)
    {
        for(int i = 0;i<n;i++)
            arr.push_back(0);
    }
    bool empty()
    {
        return N == 0;
    }
    int size()
    {
        return N;
    }
    void insert(int v)
    {
        arr[++N] = v;
        swim(N);
    }
    int del_max()
    {
        int max = arr[1];
        exch(1,N--);
        arr[N+1] = NULL;
        sink(1);
        return max;
    }
};

int main()
{
    MaxHeap max_heap(100);
    cout<<max_heap.size()<<endl;
    vector<int> c{1,2,3,4,5};
    for(auto i:c)
    {
        max_heap.insert(i);
    }
    cout<<max_heap.size()<<endl;
    int res = max_heap.del_max();
    cout<<res<<endl;

}