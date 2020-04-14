#include <iostream>
#include "graph.h"

class CC
{
private:
    vector<bool> marked;
    vector<int> id;
    int count;

    CC(Graph &G):marked(G.vertex()),id(G.vertex())
    {
        for(int s = 0;s<G.vertex();s++)
        {
            if(! marked[s])
            {
                dfs(G,s);
                count++;
            }
        }

    }

private:
    void dfs(Graph &G,int v)
    {
        marked[v] = true;
        id[v] = count;
        list<int> *l = G.adj_vertex(v);
        for(int w:*l)
        {
            if(!marked[w])
                dfs(G,w);
        }
    }

    bool connected(int v,int w)
    {
        return id[v] == id[w];
    }

    int id(int v)
    {
        return id[v];
    }

    int count_num()
    {
        return count;
    }


};