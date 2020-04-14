#include <iostream>
#include <vector>
using namespace std;

void exch(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//

void shell_sort(vector<int> &arr)
{
    int length = arr.size();
    int h = 1;
    while(h < length / 3)
        h = 3*h + 1;
    while(h >= 1) // 控制增量
    {
        for(int i = h;i<length;i++) // 单个分组内的插入排序
        {
            for(int j = i;j >= h && (arr[j] < arr[j-h]); j -= h)
                exch(arr,j,j-h);
        }
        h = h / 3;
    }

}

int main()
{
    vector<int> arr{6,5,4,3,2,1};
    shell_sort(arr);
    for(auto i:arr)
    {
        cout<<i<<endl;

    }
}