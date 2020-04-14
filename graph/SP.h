#ifndef __SP_
#define __SP_

#include <float.h>
#include <stack>

#include "EdgeWeightedDigraph.h"

class SP
{
private:
    vector<double> dist_to;
    vector<DirectedEdge> edge_to;
private:
    void relax(DirectedEdge e)
    {
        int v = e.from();
        int w = e.to();
        if(dist_to[w] > dist_to[v] + e.get_weight())
        {
            dist_to[w] = dist_to[v] + e.get_weight();
            edge_to[w] = e;
        }
    }

    void relax(EdgeWeightedDigraph &G,int v)
    {
        list<DirectedEdge> *l = G.adj_vertex();
        for(DirectedEdge e: *l)
        {
            int w = e.to();
            if(dist_to[w] > dist_to[v] + e.get_weight())
            {
                dist_to[w] = dist_to[v] + e.get_weight();
                edge_to[w] = e;
            }
        }
    }

public:
    double distTO(int v)
    {
        return dist_to[v];
    }

    bool has_path_to(int v)
    {
        return dist_to[v] < DBL_MAX;
    }

    stack<DirectedEdge> path_to(int v)
    {
        if(!has_path_to(v))
            return NULL;
        stack<DirectedEdge> path;
        for(DirectedEdge e = edge_to[v];e != NULL;e = edge_to[e.from()])
        {
            path.push(e);
        }
        return path;
    }

};

