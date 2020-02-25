#include<iostream>
#include<string.h>
using namespace std;

class node
{
    int id;
    char name[20];

    friend class dijikstra;
    public:
        node();

};

class dijikstra
{
    int vertex, edge;
    node n[10];
    int *distance, *predecessor;
    bool *visited;
    int weight[10][10];
    public:
        dijikstra();
        virtual ~dijikstra();
        void create();
        void display();
        int findminvertex();
        void dijikstra_algo(int );
        void output(int);
};

node::node()
{
    id = -1;
    strcpy(name, "####");
}

dijikstra::dijikstra()
{
    vertex = edge = 0;
    distance = predecessor = NULL;
    visited = NULL;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            weight[i][j] = 0;
        }
    }
}

dijikstra::~dijikstra(){}


void dijikstra::create()
{
    int end,edge_list,wt;
	cout<<"\nEnter vertices in graph : ";
	cin>>vertex;

	for(int i=0;i<vertex;i++)
	{
		cout<<"\nEnter vertex "<<i<<" name : ";
		cin>>n[i].name;
		n[i].id = i;
	}

	for(int i=0;i<vertex;i++)
	{
		cout<<"\nEnter edges on vertex "<<n[i].name<<" : ";
		cin>>edge_list;
		edge = edge + edge_list;

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

void dijikstra::display()
{
    cout<<"\nAdjacency matrix of graph is\n";
	cout<<"  ";
	cout<<"\n";
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

int dijikstra::findminvertex()
{
    int MinVertex=-1;

	for(int i=0;i<vertex;i++)
    {
		if( !visited[i] && (MinVertex == -1 || distance[i]< distance[MinVertex]))
        {
            MinVertex=i;
        }
	}
	return MinVertex;
}



void dijikstra::dijikstra_algo(int start_vertex){

	distance = new int[vertex];
	visited = new bool[vertex];
	predecessor= new int[vertex];

	//initialization
	for(int i=0;i<vertex;i++)
    {
		distance[i]=INT_MAX;
		visited[i]= false;
		predecessor[i]=-1;
	}

	//starting vertex has distace 0 from itself
	distance[start_vertex]=0;

	for(int j=0;j<vertex-1;j++){

		int MinVertex = findminvertex();		// select vertex with minimum distace
		visited[MinVertex]=true;

		for(int i=0;i<vertex;i++){

			if(weight[MinVertex][i] != 0 && !visited[i])
            {
				int dist = distance[MinVertex] + weight[MinVertex][i];
				if(dist < distance[i])
                {				            // update path if minimum distace found
					distance[i]=dist;
					predecessor[i]=MinVertex;		// select its predecessor for tracing path
                }
			}
		}
	}
}

void dijikstra::output(int start_vertex)
{

    cout<<"Path\tDistance\n";
	for(int i=0;i<vertex;i++)
    {
        cout<< i <<" ) ";
        //finding path from start vertex to current vertex
        if(i!=start_vertex)
        {
            int j=i;
            cout<<i;
            do{
                j=predecessor[j];
                cout<<" <- "<<j;
            }while(j!=start_vertex);
        }
        cout<<" : "<<distance[i]<<" ";
        cout<<endl;
	}

	//delete
    delete [] visited;
    delete [] distance;
}


int main()
{
    int start_vertex;
    dijikstra d;

    d.create();
    d.display();
    cout<<"\nEnter start vertex : ";
    cin>>start_vertex;
    d.dijikstra_algo(start_vertex);
    cout<<"\nShortest Path\n";
    d.output(start_vertex);
    return 0;
}
