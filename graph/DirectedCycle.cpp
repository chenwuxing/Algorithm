#include <iostream>
#include "dirgraph.h"
#include <stack>
using namespace std;

class DirectedCycle
{
private:
    vector<bool> marked;
    vector<int> edge_to;
    vector<int> on_stack; //递归调用栈上的所有顶点
    stack<int> cycle; //有向环中的所有顶点

private:
    void dfs(Digraph &G,int v)
    {
        on_stack[v] = true;
        marked[v] = true;
        list<int> *l = G.adj_vertex(v);
        for(int w: *l)
        {
            if(this->hasCycle())
                return;
            else if(!marked[w])
            {
                edge_to[w] = v;
                dfs(G,w);
            }
            else if(on_stack[w])
            {
                for(int x = v;x != w;x = edge_to[x])
                    cycle.push(x);
                cycle.push(w);
                cycle.push(v);
            }
            on_stack[v] = false;
        }
    }

public:
    DirectedCycle(Digraph &G):marked(G.vertex()),edge_to(G.vertex()),on_stack(G.vertex())
    {
        for(int v = 0;v < G.vertex();v++)
        {
            if(!marked[v])
                dfs(G,v);
        }
    }

    bool hasCycle()
    {
        return cycle.empty();
    }

    stack<int> cycle_vertex()
    {
        return cycle;
    }

};