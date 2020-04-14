#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
class BreadthFirstPaths
{
private:
    vector<bool> marked; // 到达该顶点的最短路径已知么
    vector<int> edge_to;// 到达该顶点的已知路径上的最后一个顶点
    int s; // 起点

public:
    BreadthFirstPaths(Graph &G,int s):marked(G.vertex()),edge_to(G.vertex())
    {
        this->s = s;
        bfs(G,s);
    }

    void bfs(Graph &G,int s)
    {
        queue<int> que;
        marked[s] = true; //标记起点
        que.push(s); // 将它加入队列
        while(!que.empty())
        {
            int v = que.front();
            list<int> *l = G.adj_vertex(v);
            que.pop();
            for(int w:*l) // 对于每个未被标记的相邻节点
            {
                if(!marked[w]) //对于每个未被标记的相邻节点
                {
                    edge_to[w] = v; //保存最短路径的最后一条便
                    marked[w] = true; //标记它，因为最短路径已知
                    que.push(w);
                }
            }
        }

    }

    bool has_path_to(int v)
    {
        return marked[v];
    }

    stack<int> path_to(int v)
    {
        if(!has_path_to(v))
            return NULL;
        stack<int> log;
        for(int x = v;x != s;x = edge_to[x])
        {
            log.push(x);
        }
        log.push(s);
        return log;
    }

};