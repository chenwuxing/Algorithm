#ifndef __DIJKSTRASP_
#define __DIJKSTRASP_
#include <queue>>
#include <float.h>

#include "EdgeWeightedDigraph.h"

class DijkstraSP
{
private:
    vector<DirectedEdge> edgeTo;
    vector<double> dist_to;
    priority_queue<double > pq;

private:
    void relax(EdgeWeightedDigraph &G,int v)
    {
        list<DirectedEdge> *l = G.adj_vertex(v);
        for(DirectedEdge e: *l)
        {
            int w = e.to();
            if(dist_to[w] > dist_to[v] + e.get_weight())
            {
                dist_to[w] = dist_to[v] + e.get_weight();
                edgeTo[w] = e;
                if(pq.contains(w))
                    pq.change(w,dist_to[w]);
                else
                    pq.push((w,dist_to[w]));
            }
        }
    }

public:
    DijkstraSP(EdgeWeightedDigraph &G,int s):edgeTo(G.vertex()),dist_to(G.vertex())
    {
        for(int v = 0; v < G.vertex();v++)
            dist_to[v] = DBL_MAX;
        dist_to[s] = 0.0;
        pq.push(s,0.0);
        while(!pq.empty())
        {
            int min = pq.top();
            pq.pop();
        }

    }


};

