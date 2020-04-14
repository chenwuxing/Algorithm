#include "Edge.h"
#include <list>
using namespace std;

class EdgeWeightedGraph
{
private:
    int V; //顶点总数
    int E; //边的总数
    vector<list<Edge>*> *adj;

public:
    EdgeWeightedGraph(int vertex)
    {
        V = vertex;
        E = 0;
        adj = new vector<list<Edge>*>;
        for(int v = 0; v < vertex;v++)
        {
            list<Edge> *l = new list<Edge>;
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

    void add_edge(Edge e)
    {
        int v = e.either();
        int w = e.other(v);
        (*adj)[v]->push_back(e);
        (*adj)[w]->push_back(e);
        E++;
    }

    list<Edge>* adj_vertex(int v)
    {
        return (*adj)[v];
    }

    list<Edge> edges()
    {
        list<Edge> b;
        for(int v = 0;v < V;v++)
        {
            list<Edge> *l = (*adj)[v];
            for(Edge e: *l)
            {
                if(e.other(v) > v)
                    b.push_back(e);
            }
        }
        return b;
    }
};