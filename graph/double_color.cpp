#include <iostream>
#include "graph.h"

class TwoColor
{
private:
    vector<bool> marked;
    vector<bool> color;
    bool is_two_colorable = true;

private:
    void dfs(Graph &G,int v)
    {
        marked[v] = true;
        list<int> *l = G.adj_vertex(v);
        for(int w: *l)
        {
            if(! marked[w])
            {
                color[w] = !color[v];
                dfs(G,w);
            }
            else if(color[w] == color[v])
                is_two_colorable = false;
        }
    }

public:
    TwoColor(Graph &G):marked(G.vertex()),color(G.vertex())
    {
        for(int s = 0;s < G.vertex();s++)
        {
            if(! marked[s])
                dfs(G,s);
        }

    }

    bool is_bi_partite()
    {
        return is_two_colorable;
    }
};