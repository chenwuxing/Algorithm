#include <iostream>
#include <vector>
using namespace std;

void exch(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swim(vector<int> &arr,int k)
{
    while(k > 1 && arr[k] > arr[k/2])
    {
        exch(arr,k,k/2);
        k /= 2;
    }
}

void sink(vector<int> &arr,int k,int length)
{
    while(2*k <= length)
    {
        int j = 2*k;
        if(j < length && (arr[j] < arr[j+1]))
            j++;
        if(arr[k] > arr[j])
            break;
        exch(arr,k,j);
        k = j;

    }
}

void heap_sort(vector<int> &arr)
{
    int N = arr.size()-1;
    for(int k = N/2;k>=1;k--)
    {
        sink(arr,k,N);
    }
    while(N > 1)
    {
        exch(arr,1,N--);
        sink(arr,1,N);
    }
}

int main()
{
    vector<int> arr{1000,8,2,6,9,1,10};
    heap_sort(arr);
    for(auto i:arr)
    {
        cout<<i<<endl;
    }
}




