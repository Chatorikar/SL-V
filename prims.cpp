#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;

class node
{
    char name[20];
    friend class prims;
    public:
        node();
};

class prims
{
    int vertex;
    node *n;
    int **weight;
    public:
        prims();
        virtual ~prims();
        void create();
        void display();
        int findminvertex(bool [], int []);
        void mst();
        void primmst(int []);
};



node::node()
{
    strcpy(name, "####");
}

prims::prims()
{
    vertex = 0;
    n = NULL;
    weight = NULL;
}

prims::~prims(){}

void prims::create()
{
    int end,edge_list,wt;
	cout<<"Enter vertices in graph : ";
	cin>>vertex;

	weight = new int*[vertex];
	n = new node[vertex];

	for(int i=0;i<vertex;i++)
    {
        weight[i] = new int[vertex];
    }

    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            weight[i][j] = 0;
        }
    }

	for(int i=0;i<vertex;i++)
	{
		cout<<"\nEnter vertex "<<i<<" name : ";
		cin>>n[i].name;
	}

	for(int i=0;i<vertex;i++)
	{
		cout<<"\nEnter edges on vertex "<<n[i].name<<" : ";
		cin>>edge_list;

		for(int j=0;j<edge_list;j++)
		{
			cout<<"Enter end vertex : ";
			cin>>end;

			cout<<"Enter weight between "<<n[i].name<<" and "<<n[end].name<<" edge : ";
			cin>>wt;

			weight[i][end] = weight[end][i] = wt;
		}
	}
}

void prims::display()
{
    cout<<"\nAdjacency matrix of graph is\n";
	cout<<"  ";
	for(int i=0;i<vertex;i++)
	{
		cout<<n[i].name<<" ";
	}
	cout<<"\n";
	for(int i=0;i<vertex;i++)
	{
		cout<<n[i].name<<" ";
		for(int j=0;j<vertex;j++)
		{
			cout<<weight[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int prims::findminvertex(bool visited[], int distance[])
{
    int minval = INT_MAX;
    int min_index;
    for(int i=0;i<vertex;i++)
    {
        if(visited[i] == false && distance[i] < minval)
        {
            minval = distance[i];
            min_index = i;
        }
    }

    return min_index;
}

void prims::primmst(int predecessor[])
{
    cout<<"\nEdge \tWeight\n";
    for(int i=1;i<vertex;i++)
    {
        cout<<n[predecessor[i]].name<<" - "<<n[i].name<<"  "<<weight[i][predecessor[i]];
        cout<<endl;
    }
}

void prims::mst()
{
    bool *visited = new bool[vertex];
    int *distance = new int[vertex];
    int *predecessor = new int[vertex];

    int min_index;
    for(int i=0;i<vertex;i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;
    predecessor[0] = -1;

    for(int i=0;i<vertex-1;i++)
    {
        min_index = findminvertex(visited, distance);
        visited[min_index] = true;

        for(int j=0;j<vertex;j++)
        {
            if (weight[min_index][j] && visited[j] == false && weight[min_index][j] <  distance[j])
             predecessor[j]  = min_index, distance[j] = weight[min_index][j];
        }
    }

    primmst(predecessor);
}

int main()
{
    prims p;
    p.create();
    p.display();
    p.mst();
    return 0;
}
