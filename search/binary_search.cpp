#include<iostream>
#include<vector>
using namespace std;

// 一般二分查找
int binary_search(vector<int> &arr,int key)
{
		int low = 0;
		int high = arr.size()-1;

		while(low <= high)
		{
				int mid = (low + high) /2;
				if(arr[mid] > key)
						high = mid -1;
				else if(arr[mid] < key)
						low = mid + 1;
				if(arr[mid] == key)
						return mid;

		}
		return -1;
}

// 寻找左边界的二分查找
int binarySearch(vector<int> &arr,int target)
{
    if(arr.size() == 0)
        return -1;
    int left = 0;
    int right = arr.size();
    
    while(left < right)
    {
        int mid = (right+left)/2;
        
        if(arr[mid] == target)
            right = mid;
        else if(arr[mid] < target)
            left = mid +1;
        else if(arr[mid] > target)
            right = mid;

    }

    if(left == arr.size())
        return -1;
    return arr[left] == target ? left : -1;
}

// 寻找右侧边界的二分查找
int binarySearch(vector<int> &arr,int target)
{
    if(arr.size() == 0)
        return -1;
    int left = 0;
    int right = arr.size();
    
    while(left < right)
    {
        int mid = (right+left)/2;
        
        if(arr[mid] == target)
            left = mid + 1;
        else if(arr[mid] < target)
            left = mid +1;
        else if(arr[mid] > target)
            right = mid;

    }

    if(left == 0)
        return -1;
    return arr[left-1] == target ? left-1 : -1;
}

int main()
{
		vector<int> arr{1,2,3,4,5,6};
		int result = binary_search(arr,5);
		cout<<result<<endl;
}




