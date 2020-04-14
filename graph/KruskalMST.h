#include <queue>
#include "EdgeWeightedGraph.h"

using namespace std;

class KruskalMST
{
private:
    queue<Edge> mst; //存放最小生成树的边

public:
    KruskalMST(EdgeWeightedGraph &G)
    {
        priority_queue<Edge> pq;
        for(Edge e: G.edges())
            pq.insert(e);
        UF uf(G.vertex());

        while(!pq.empty() && mst.size() < G.vertex()-1)
        {
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int w = e.other(v);
            if(uf.connected(v,w)) //忽略失效的边
                continue;
            uf.union(v,w);  //合并分量
            mst.push(e); // 将边添加到最小生成树中
        }
    }

    queue<Edge> edges()
    {
        return mst;
    }

    double weight()
    {
        
    }

};