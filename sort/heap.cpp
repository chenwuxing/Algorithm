#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool small(int a,int b)
{
    return a > b;
}

int main()
{
    vector<int> arr{1,62,6,9,0,1,45};
    make_heap(arr.begin(),arr.end());
    for(auto i: arr)
        cout<<i<<endl;
    cout<<"------------------"<<endl;
    arr.push_back(90);
    push_heap(arr.begin(),arr.end());
    for(auto i : arr)
        cout<<i<<endl;
    pop_heap(arr.begin(),arr.end());
    int lar = arr.back();
    cout<<lar<<endl;
    arr.pop_back();
    cout<<"-----------"<<endl;
    for(auto i : arr)
        cout<<i<<endl;
    
    make_heap(arr.begin(),arr.end(),small);
    for(auto i : arr)
        cout<<i<<endl;
    
    
   
}