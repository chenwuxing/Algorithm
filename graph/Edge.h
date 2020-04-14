#ifndef __EDGE_H__
#define __EDGE_H__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Edge
{
private:
    int v; // 顶点之一
    int w; // 另一个顶点
    double weight; // 边的权重

public:
    Edge(int v,int w, double weight)
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    double get_weight()
    {
        return weight;
    }

    int either()
    {
        return v;
    }

    int other(int vertex)
    {
        if(vertex == v)
            return w;
        else if(vertex == w)
            return v;
    }

    int compare_to(Edge &that)
    {
        if(this->weight() < that.weight())
            return -1;
        else if(this->weight() > that.weight())
            return 1;
        else
            return 0;
    }

    string tostring()
    {
        stringstream v_str,w_str,weight_str;
        v_str<<v;
        w_str<<w;
        weight_str<<weight;
        string v_res(v_str.str());
        string w_res(w_str.str());
        string weight_res(weight_str.str());
        string res = v_res + w_res + weight_res;
        return res;

    }
};

#endif
