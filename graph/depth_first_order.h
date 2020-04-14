#include <iostream>
#include <stack>
#include <queue>
#include "dirgraph.h"

class DepthFirstOrder
{
private:
    vector<bool> marked;
    queue<int> pre; //所有顶点的前序排列
    queue<int> post; // 所有顶点的后序排列
    stack<int> reversePost; // 所有顶点的逆后序排列

private:
    void dfs(Digraph &G,int v)
    {
        pre.push(v);
        marked[v] = true;
        list<int> *l = G.adj_vertex(v);
        for(int w: *l)
        {
            if(! marked[w])
                dfs(G,w);
        }
        post.push(v);
        reversePost.push(v);

    }

public:
    DepthFirstOrder(Digraph &G):marked(G.vertex())
    {
        for(int v = 0;v < G.vertex();v++)
            if(!marked[v])
                dfs(G,v);


    }

    queue<int> pre_order()
    {
        return pre;
    }
    queue<int> post_order()
    {
        return post;
    }
    stack<int> reverse_post_order()
    {
        return reversePost;
    }

};