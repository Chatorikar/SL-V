#include<iostream>
#include<string.h>
using namespace std;

void funct(int,int,int,struct student [],int );

struct student
{
	char rollno[9];
	int arts;
	int science;
};

void func(int sub,int min,int max,struct student S[],int n)
{
	int index[100],i,min_sort,j,temp;
	for(i=0;i<n;i++)
		index[i]=i;
	if(sub==1)
	{
		for (i=0;i<n-1;i++)     
    	{ 
        	min_sort=i; 
        	for(j=i+1;j<n;j++) 
        	{ 
            	if(S[index[min_sort]].arts > S[index[j]].arts) 
                	min_sort=j; 
        	} 
        	if(min_sort!=i) 
        	{ 
            	temp=index[min_sort]; 
            	index[min_sort]=index[i]; 
            	index[i]=temp; 
        	} 
    	}
    	cout<<"\nSorted Array";
    	cout<<"\nRollno\tArts\n";
    	for(i=0;i<n;i++)
    	{ 
    		if(min<=S[index[i]].arts && max>=S[index[i]].arts)
        		cout<<S[index[i]].rollno<<"\t"<<S[index[i]].arts<<"\n";
        }  
	}
	else
	{
		for (i=0;i<n-1;i++)     
    	{ 
        	min_sort=i; 
        	for(j=i+1;j<n;j++) 
        	{ 
            	if(S[index[min_sort]].science > S[index[j]].science) 
                	min_sort=j; 
        	} 
        	if(min_sort!=i) 
        	{ 
            	temp=index[min_sort]; 
            	index[min_sort]=index[i]; 
            	index[i]=temp; 
        	} 
    	}
    	cout<<"\nSorted Array";
    	cout<<"\nRollno\tScience\n";
    	for(i=0;i<n;i++)
    	{ 
    		if(min<=S[index[i]].science && max>=S[index[i]].science)
        		cout<<S[index[i]].rollno<<"\t"<<S[index[i]].science<<"\n";
        }  
	}
}

int main()
{
	struct student S[100];
	int n,i,sub,min,max;
	
	cout<<"\nEnter the number of records - ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the roll no of Student "<<(i+1)<<" - ";
		cin>>S[i].rollno;
		cout<<"\nEnter the arts marks of Student "<<(i+1)<<" - ";
		cin>>S[i].arts;
		cout<<"\nEnter the science marks no of Student "<<(i+1)<<" - ";
		cin>>S[i].science;
	}
	
	cout<<"\nDatabase";
	cout<<"\nRollno\tarts\tscience\n";
	for(i=0;i<n;i++)
	{
		cout<<S[i].rollno<<"\t"<<S[i].arts<<"\t"<<S[i].science<<"\n";	
	}
	
	label:
	cout<<"\nSort according to - 1.Arts  2.Science\n";
	cin>>sub;
	cout<<"\nEnter the minimum value - ";
	cin>>min;
	cout<<"\nEnter the maximum value - ";
	cin>>max;
	
	if(sub==1 || sub==2) 
	{
		func(sub,min,max,S,n);		
	}
	else
	{
		cout<<"\nEnter correct input\n";
		goto label;
	}	
	
	cout<<"\nDatabase";
	cout<<"\nRollno\tarts\tscience\n";
	for(i=0;i<n;i++)
	{
		cout<<S[i].rollno<<"\t"<<S[i].arts<<"\t"<<S[i].science<<"\n";	
	}
	
	return 0;
}
