#ifndef __EDGE_WEIGHTED_DIGRAPH_
#define __EDGE_WEIGHTED_DIGRAPH_

#include "DirectedEdge.h"
#include <vector>
#include <list>

using namespace std;

class EdgeWeightedDigraph
{
private:
    int V; // 顶点总数
    int E; // 边的总数
    vector<list<int>*> *adj; // 邻接表

public:
    EdgeWeightedDigraph(int V)
    {
        this->V = V;
        this->E = 0;
        adj = new vector<list<int>*>;
        for(int v = 0;v < V;v++)
        {
            list<int> *l = new list<int>;
            adj->push_back(l);
        }
    }

    int vertex()
    {
        return V;
    }

    int edge()
    {
        return E;
    }

    void add_edge(DirectedEdge e)
    {
        (*adj)[e.from()]->push_back(e);
        E++;
    }

    list<DirectedEdge>* adj_vertex(int v)
    {
        return (*adj)[v];
    }

    list<DirectedEdge> edges()
    {
        list<DirectedEdge> res;
        for(int v = 0;v < V;v++)
        {
            list<DirectedEdge> *l = adj_vertex(v);
            for(DirectedEdge e : *l)
            {
                res.push_back(e);
            }

        }
        return res;
    }

};

#endif