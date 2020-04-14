#include<iostream>
#include <vector>
using namespace std;

void exch(vector<int> &arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insert_sort(vector<int> &arr)
{
    int length = arr.size();
    for(int i = 1;i < length;i++)
    {
        int move = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > move) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = move;


    }
}

int main()
{
    vector<int> arr{6,5,4,3,2,1};
    insert_sort(arr);
    for(auto i:arr)
    {
        cout<<i<<endl;
    }

}