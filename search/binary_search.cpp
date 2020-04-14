#include<iostream>
#include<vector>
using namespace std;


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

int main()
{
		vector<int> arr{1,2,3,4,5,6};
		int result = binary_search(arr,5);
		cout<<result<<endl;
}




