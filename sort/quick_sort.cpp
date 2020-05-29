#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr,int low,int high)
{
    int i = low;
    int j = high;
    int benchMark = arr[low];

    while(true)
    {
        while(arr[i] <= benchMark)
        {
            i++;
            if(i == high)
                break;
        }

        while(arr[j] >= benchMark)
        {
            j--;
            if(j == low)
                break;
        }
        
        if(i >= j)
            break;
        
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr,int low,int high)
{
    if(low >= high)
        return;
    int index = partition(arr,low,high);
    quickSort(arr,low,index-1);
    quickSort(arr,index+1,high);
}