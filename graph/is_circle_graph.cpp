#include <iostream>
#include "graph.h"

using namespace std;

class Cycle
{
private:
    vector<bool> marked;
    bool has_cycle;

private:
    void dfs(Graph &G,int v,int u)
    {
        marked[v] = true;
        list<int> *l = G.adj_vertex(v);
        for(int w:*l)
        {
            if(! marked[w])
                dfs(G,w,v);
            else if(w != u) // 访问过的节点不是当前节点的父节点
                has_cycle = true;
        }
    }

public:
    Cycle(Graph &G):marked(G.vertex())
    {
        for(int s = 0;s < G.vertex();s++)
        {
            if(! marked[s])
                dfs(G,s,s);
        }
    }

    bool is_cycle()
    {
        return has_cycle;
    }
};