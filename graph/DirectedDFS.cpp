#include "dirgraph.h"

using namespace std;

class DirectedDFS
{
private:
    vector<bool> marked;

private:
    void dfs(Digraph &G,int v)
    {
        marked[v] = true;
        list<int> *l = G.adj_vertex(v);
        for(int w : *l)
        {
            if(! marked[w])
                dfs(G,w);
        }
    }

public:

    DirectedDFS(Digraph &G,int s):marked(G.vertex())
    {
        dfs(G,s);
    }

    DirectedDFS(Digraph &G,vector<int> &sources):marked(G.vertex())
    {
        for(int s:sources)
        {
            if(!marked[s])
                dfs(G,s);
        }
    }

    bool is_marked(int v)
    {
        return marked[v];
    }


};