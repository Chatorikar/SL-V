
#include <iostream>
#include<string.h>
using namespace std;

class node
{
	int weight, vertex_id;
	char vertex_name[20];
	node *next;
	public:
		node();
		friend class graph;

};

class sparse
{
	int start,end,val;
	public:
		sparse();
		friend class graph;
};


class graph
{
	int vertex,edge;
	node *arr[20];
	sparse s[20];
	int mst[10][2];
	public:
		graph();
		void create_vertex();
		void display_vertex();
		void input();
		void display_graph();
		void display_sparse();
		void Sortedge();
		void make_set(int []);
		void kruskal_mst();
};

node::node()
{
	weight = vertex_id = -1;
	strcpy(vertex_name, "####");
	next = NULL;
}

sparse::sparse()
{
	start = end = val = -1;
}

graph::graph()
{
	vertex = edge = 0;
	for(int i=0;i<20;i++)
	{
		arr[i] = NULL;
	}
}

void graph::create_vertex()
{
	cout<<"Enter no of vertices in graph : ";
	cin>>vertex;

	for(int i=0;i<vertex;i++)
	{
		arr[i] = new node;
		cout<<"\nEnter vertex "<<i<<" name : ";
		cin>>arr[i]->vertex_name;
		arr[i]->next = NULL;
		arr[i]->vertex_id = i;
		arr[i]->weight = 0;
	}
}

void graph::display_vertex()
{
	for(int i=0;i<vertex;i++)
	{
		cout<<arr[i]->vertex_name<<" "<<arr[i]->vertex_id<<" "<<arr[i]->weight<<" \n";
	}
}

void graph::input()
{
	int edge_list,k=1,last;
    node *p;
	for(int i=0;i<vertex;i++)
	{
		cout<<"\nEnter edges connected to vertex "<<arr[i]->vertex_name<<" : ";
		cin>>edge_list;
		edge = edge + edge_list;
		for(int j=0;j<edge_list;j++)
		{
		    node *temp = new node;
			cout<<"\nEnter vertex id : ";
			cin>>temp->vertex_id;
            last = temp->vertex_id;

			cout<<"Enter weight : ";
			cin>>temp->weight;


			strcpy(temp->vertex_name, arr[temp->vertex_id]->vertex_name);

			temp->next = NULL;

			if(arr[i]->next == NULL)
			{
				arr[i]->next = temp;
				temp->next = NULL;
			}
			else
			{
				p = arr[i]->next;
				while(p->next!=NULL)
				{
					p = p->next;
				}
				p->next = temp;
				temp->next = NULL;
			}

            s[k].start = i;
            s[k].end = last;
            s[k++].val = temp->weight;

            node *q = new node;
            q->vertex_id = arr[i]->vertex_id;
            q->weight = temp->weight;
            strcpy(q->vertex_name, arr[i]->vertex_name);
            q->next = NULL;

            if(arr[last]->next == NULL)
            {
                arr[last]->next = q;
                q->next = NULL;
            }
            else
            {
                node *temp1 = arr[last]->next;
                while(temp1->next!=NULL)
                {
                    temp1 = temp1->next;
                }

                temp1->next = q;
                q->next = NULL;
            }
		}
	}

	s[0].start = vertex;
	s[0].end = vertex;
	s[0].val = k;
}

void graph::display_graph()
{
	node *p;
	for(int i=0;i<vertex;i++){
		for(p = arr[i];p!=NULL;p = p->next){
            cout<<" | "<<p->vertex_id<<" | "<<p->vertex_name<<" | "<<p->weight<<" | ";
            if(p->next != NULL){
                cout<<"->";
            }
        }
        cout<<endl;
	}
}

void graph::display_sparse()
{
    for(int i=0;i<s[0].val;i++){
        cout<<s[i].start<<" "<<s[i].end<<" "<<s[i].val<<endl;
    }
}

void  graph::Sortedge()
{
    sparse temp;
    for(int i=1;i<s[0].val;i++)
    {
       for(int j=1;j<s[0].val-1;j++)
       {
           if(s[j].val>s[j+1].val)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
       }
    }
}


int Find(int v, int set[])
{
    return set[v];
}
void graph::make_set(int set[])
{
	for(int i=0;i<vertex;i++)
    {
        set[i] = i;
    }
}
void Union(int i, int j, int set[])
{
   set[i]=j;
}


void graph::kruskal_mst()
{
	int edgecount=s[0].val, mincost=0, set[10];
    make_set(set);
    int i,j, v=0,m=0,k;

	Sortedge();
	cout<<"\nSparse matrix is\n";
	display_sparse();
	int e=1;
	while((edgecount>0)&&(v<vertex-1))
	{
      sparse temp = s[e++];
      j = Find(temp.start,set);
      k = Find(temp.end,set);
      if(j!=k)
      {
    	   mst[m][0]=temp.start;
    	   mst[m++][1]=temp.end;
    	   mincost = mincost+temp.val;
    	   Union(j,k,set);
    	   edgecount--;
    	   v++;
      }

	}

    if(v!=s[0].start-1)
        cout<<"Spanning tree is not possible";
    else
    {
        cout<<"\nMST is\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
               cout<<mst[i][j]<<" ";
            }
        }
    }
}


int main()
{

	int ch;
	graph g;

	do
	{
		cout<<"\n-------------MENU---------------\n";
		cout<<"1-Create Graph\n2-Find MST\n3-Exit";
		cout<<"\n--------------------------------\n";

		cout<<"\nEnter choice : ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
					g.create_vertex();
					g.input();
					cout<<"\nAdjacency list of graph\n\n";
					g.display_graph();
					break;

			case 2:
					g.kruskal_mst();
					break;
		}
	}while(ch!=3);

	return 0;
}
