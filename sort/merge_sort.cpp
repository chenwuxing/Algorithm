#include<iostream>
#include <vector>
using namespace std;



void merge_two_list(vector<int> &arr,int left,int mid,int right)
{
    int length = right - left + 1;
    vector<int> tmp(length);
    int start = left;
    int tmp_index = 0;
    int tail_left = mid -1;
    while(left <= tail_left && mid <= right)
    {
        if(arr[left] <= arr[mid])
        {
            tmp[tmp_index] = arr[left];
            left++;
        }
        else
        {
            tmp[tmp_index] = arr[mid];
            mid++;
        }
        tmp_index++;
    }
    if(left > tail_left)
    {
        while(mid <= right)
        {
            tmp[tmp_index] = arr[mid];
            mid++;
            tmp_index++;
        }
    }
    if(mid > right)
    {
        while(left <= tail_left)
        {
            tmp[tmp_index] = arr[left];
            left++;
            tmp_index++;
        }
    }
    for(int i = 0;i<length;i++)
        arr[i+start] = tmp[i];
}

// 迭代法实现
void merge_sort(vector<int> &arr)
{
    int length = arr.size();
    for(int step = 1;step < length;step <<= 1)
    {
        int offset = step + step;
        for(int index = 0;index < length;index = index+offset)
        {
            merge_two_list(arr,index,min(index + step,length-1),min(index+offset-1,length-1));
        }
    }
}

// 递归实现
void merge_sort_recursive(vector<int> &arr,int left,int right)
{
    if(left >= right)
        return;

    int mid = (right - left)/2 +left;
    merge_sort_recursive(arr,left,mid);
    merge_sort_recursive(arr,mid + 1,right);
    merge_two_list(arr,left,mid + 1,right);
}

int main()
{
    vector<int> arr{9,8,7,6,5,4,3,2,1};
    merge_sort_recursive(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<endl;
    }
}