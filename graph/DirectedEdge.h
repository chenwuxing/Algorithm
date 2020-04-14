#ifndef __DIRECTED_EDGE_H
#define __DIRECTED_EDGE_H

#include <vector>
using namespace std;

class DirectedEdge
{
private:
    int v; // 边的起点
    int w; // 边的终点
    double weight; // 边的权重

public:
    DirectedEdge(int v, int w,double weight)
    {
        this->v= v;
        this->w = w;
        this->weight = weight;
    }

    double get_weight()
    {
        return weight;
    }

    int from()
    {
        return v;
    }

    int to()
    {
        return w;
    }

};

#endif