#include<iostream>
#include<vector>

using namespace std;

void shell(vector<int> &arr)
{
		int len = arr.size();
		int gap =1;
		while(gap < len)
				gap = gap*3 +1;
		
		while(gap >= 1)
		{
				for(int i = gap;i < len;i++)
				{
						int tmp = arr[i];
						int j = i - gap;
						// 跨区间排序
						while(j >= 0 && arr[j] > tmp)
						{
								arr[j+gap] = arr[j];
								j -= gap;
						}
						arr[j+gap] = tmp;
				}
				gap /= 3;
		}
}

int main()
{
		vector<int> arr{9,8,7,6,5,4,3,2,1};
		shell(arr);
		for(auto i:arr)
			cout<<i<<endl;
}

