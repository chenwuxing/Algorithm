#include<iostream>
#include<vector>
using namespace std;



int leftBound(vector<int> &arr,int target)
{
    int len = arr.size();
    int left = 0,right = len -1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] < target)
            left = mid + 1;
        else if(arr[mid] > target)
            right = mid - 1;
        else if(arr[mid] == target)
            right = mid - 1;       
    }
    // 检查left越界情况，数组中的数都比target小
    if(left >= len || arr[left] != target)
        return -1;
    return left;
}

int rightBound(vector<int> &arr,int target)
{
    int len = arr.size();
    int left = 0,right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] < target)
            left = mid + 1;
        else if(arr[mid] > target)
            right = mid - 1;
        else if(arr[mid] == target)
            left = mid + 1;
    }
    if(right < 0 || arr[right] != target)
        return -1;
    return right;
}

int main()
{
    vector<int> arr{1,2,2,3,5,6,6,8};
    cout<<leftBound(arr,2)<<endl;
    cout<<rightBound(arr,2)<<endl;
    cout<<leftBound(arr,9)<<endl;
    system("pause");
}