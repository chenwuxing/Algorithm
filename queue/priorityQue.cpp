#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main()
{
    auto cmp = [] (auto &lhs,auto rhs)  {return lhs > rhs;};
    priority_queue<int,vector<int>,decltype(cmp)> q(cmp);

    for(auto &i :{11,2,76,908,13})
        q.push(i);
    
    while(!q.empty())
    {
        cout<<q.top()<<",";
        q.pop();
    }
    cout<<"\b\b"<<endl;
    return 0;
}