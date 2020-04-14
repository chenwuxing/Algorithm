#include <iostream>
#include <vector>
#include "dirgraph.h"
#include  "depth_first_order.h"

using namespace std;

class KosarajuSCC
{
private:
    vector<bool> marked; // 已访问过的节点
    vector<int> id; // 强连通分量的标识符
    int count; // 强连通分量的数量

private:
    void dfs(Digraph &G,int v)
    {
        marked[v] = true;
        id[v] = count;
        list<int> *l = G.adj_vertex(v);
        for(int w: *l)
        {
            if(!marked[w])
                dfs(G,w);
        }
    }

public:
    KosarajuSCC(Digraph &G):marked(G.vertex()),id(G.vertex())
    {
        DepthFirstOrder order(G.reverse());
        stack<int> reverse = order.reverse_post_order();
        for(int s:reverse)
        {
            if(!marked[s])
            {
                dfs(G,s);
                count++;
            }

        }
    }

    bool stronglyConnected(int v,int w)
    {
        return id[v] = id[w];
    }

    int get_id(int v)
    {
        return id[v];
    }

    int get_count()
    {
        return count;
    }


};