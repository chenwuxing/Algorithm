#include<vector>
#include<iostream>
using namespace std;



void mergeTwo(vector<int> &nums,int left,int mid,int right)
{
    vector<int> tmp;
    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(nums[i] <= nums[j])
        {
            tmp.push_back(nums[i++]);
        }
        else
        {
            tmp.push_back(nums[j++]);
        }
    }
    while(i <= mid)
        tmp.push_back(nums[i++]);
    
    while(j <= right)
        tmp.push_back(nums[j++]);

    for(int m = 0,n = left;m < tmp.size();m++,n++)
        nums[n] = tmp[m];
}

void mergeSort(vector<int> &nums,int left,int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid + 1,right);
    mergeTwo(nums,left,mid,right);
}

int main()
{
    vector<int> arr{4,21,5,9,0,1,3};
    mergeSort(arr,0,(int)arr.size()-1);
    for(auto &i:arr)
    {
        cout<<i<<endl;
    }
    system("pause");
}