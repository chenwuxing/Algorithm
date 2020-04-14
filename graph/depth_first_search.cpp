#include <iostream>
#include <stack>
#include "graph.h"
using namespace std;

class DepthFirstSearch
{
private:
    vector<bool> marked; // 这个顶点上调用过dfs()了么
    int count;
    vector<int> edge_to; // 从起点到一个顶点的已知路径上的最后一个顶点
    int s; // 起点

private:
    void dfs(Graph &G,int v)
    {
        marked[v] = true;
        count++;
        list<int> *l = G.adj_vertex(v);
        for(int w:*l)
        {
            if(! marked[w])
            {
                edge_to[w] = v;
                dfs(G, w);
            }
        }
    }

public:
    DepthFirstSearch(Graph &G,int s) :marked(G.vertex()),count(0),edge_to(G.vertex())
    {
        this->s = s;
        dfs(G,s);

    }

    bool is_marked(int w)
    {
        return marked[w];
    }

    int count_of_vertex()
    {
        return count;
    }

    bool has_path_to(int v)
    {
        return marked[v];
    }

    stack<int> path_to(int v) //深度优先搜索从起始点到任意节点的路径
    {
        if(! has_path_to(v))
            return NULL;
        stack<int> path;
        for(int x = v;x != s;x = edge_to[x])
            path.push(x);
        path.push(s);
        return path;
    }


};

int main()
{
    Graph g(5);
    g.build_adj();
    DepthFirstSearch s(g,0);
    cout<<"graph has "<<s.count_of_vertex()<<"vertex"<<endl;

}