#ifndef __LAZY_PRIM_MST_H
#define __LAZY_PRIM_MST_H

#include <queue>
#include "EdgeWeightedGraph.h"


using namespace std;

class LazyPrimMST
{
private:
    vector<bool> marked; // 最小生成树的顶点
    queue<Edge> mst; // 最小生成树的边
    priority_queue<Edge> pq; //横切边(包括失效的边)

private:
    void visit(EdgeWeightedGraph &G,int v)
    {
        //标记顶点v并将所有连接v和未标记顶点的边加入pq
        marked[v] = true;
        list<Edge> *l = G.adj_vertex(v);
        for(Edge e : *l)
        {
            if(!marked[e.other(v)])
                pq.push(e);
        }
    }
public:
    LazyPrimMST(EdgeWeightedGraph &G):marked(G.vertex())
    {
        visit(G,0);
        while(! pq.empty())
        {
            Edge e = pq.top(); // 从pq中得到权重最小的边
            pq.pop();

            int v = e.either();
            int w = e.other(v);
            if(marked[v] && marked[w]) //跳过失效的边
                continue;
            mst.push(e); // 将边添加到树中
            if(!marked[v]) // 将顶点v或w添加到树中
                visit(G,v);
            if(!marked[w])
                visit(G,w);


        }
    }

    queue<Edge> edges()
    {
        return mst;
    }

};

#endif