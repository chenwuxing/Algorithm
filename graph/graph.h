#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph
{
private:
    int V;
    int E;
    vector<list<int> *> *adj;

public:
    Graph(int vertex)
    {
        V = vertex;
        E = 0;
        adj = new vector<list<int>*>;
        for(int v = 0;v < V;v++)
        {
            list<int> *l = new list<int>;
            adj->push_back(l);
        }
    }



    int vertex(){return V;}

    int edge() {return E;}

    void add_edge(int v,int w)
    {
        (*adj)[v]->push_back(w);
        (*adj)[w]->push_back(v);
        E++;
    }

    list<int>* adj_vertex(int v)
    {
        return (*adj)[v];
    }

    void build_adj()
    {
        int vertex_num;
        int edge_num;
        cout<<"please input the num of vertex"<<endl;
        cin>>vertex_num;
        cout<<"please input the num of edge"<<endl;
        cin>>edge_num;

        cout<<"begin to init the adj"<<endl;

        int x1;
        int x2;
        for(int i = 0;i<edge_num;i++)
        {
            cout<<"input the "<<i<<" "<<"edge's vertex";
            cout<<"please input the first vertex"<<endl;

            cin>>x1;
            cout<<"please input the second vertex"<<endl;
            cin>>x2;
            add_edge(x1,x2);
        }

    }






};


