#include<iostream>
#include<vector>
using namespace std;

void exch(vector<int> &arr,int i,int j)
{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
}



void select_sort(vector<int> &arr)
{
		int length = arr.size();
		for(int i = 0;i<length;i++)
		{
				int min = i;
				for(int j = i+1;j<length;j++)
				{
						if(arr[j] < arr[min])
						{
							min = j;
						}
				}
				exch(arr,i,min);
		}
}

int main()
{
		vector<int> arr{6,5,4,3,2,1};
		select_sort(arr);
		for(auto i:arr)
		{
				cout<<i<<endl;
		}
}


