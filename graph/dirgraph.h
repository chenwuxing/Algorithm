#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Digraph
{
private:
    int V;
    int E;
    vector<list<int> *> *adj;

public:
    Digraph(int v)
    {
        this->V = v;
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

    void add_edge(int v,int w)
    {
        (*adj)[v]->push_back(w);
        E++;
    }

    list<int>* adj_vertex(int v)
    {
        return (*adj)[v];
    }

    Digraph reverse()
    {
        Digraph R(this->V);
        for(int v = 0;v< V;v++)
        {
            list<int> *l = this->adj_vertex(v);
            for(int w : *l)
            {
                R.add_edge(w,v);
            }
        }
        return R;
    }

    void build_dirgraph()
    {
        int edge_num;
        cout<<"please input the num of edge:"<<endl;
        cin>>edge_num;
        int x1,x2;
        for(int i = 0;i < edge_num;i++)
        {
            cout<<"input the first vertex of "<<i<<" edge"<<endl;
            cin>>x1;
            cout<<"input the second vertex of "<<i<<" edge"<<endl;
            cin>>x2;
            add_edge(x1,x2);

        }
    }
};

