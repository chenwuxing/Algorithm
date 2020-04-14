#include <iostream>
#include <vector>
using namespace std;

void exch(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

int partition(vector<int> &arr,int lo,int hi)
{
    int i = lo;
    int j = hi + 1;
    int v = arr[lo];
    while(true)
    {
        while(arr[++i] <= v){
            if(i == hi)
                break;

        }
        while(arr[--j] >= v){
            if(j == lo)
                break;

        }
        if(i >= j)
            break;
        exch(arr,i,j);
    }
    exch(arr,lo,j);
    return j;
}

void quick_sort(vector<int> &arr,int lo,int hi)
{
    if(hi <= lo)
        return;
    int j = partition(arr,lo,hi);
    quick_sort(arr,lo,j-1);
    quick_sort(arr,j+1,hi);
}

int main()
{
    vector<int> arr{6,5,4,3,2,1,6,6,6,1,3,2};
    quick_sort(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<endl;
    }
}