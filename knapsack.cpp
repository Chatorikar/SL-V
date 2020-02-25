#include<bits/stdc++.h>
#define N 100
using namespace std;

int knapsack_function(int n,int weight[],int value[],int capacity);

int knapsack_function(int n,int weight[],int value[],int capacity)
{
	int K[n+1][capacity+1],i,j;
	for(i=0;i<1;i++)
	{
		for(j=0;j<capacity+1;j++)
		{
			K[i][j]=0;
		}
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<1;j++)
		{
			K[i][j]=0;
		}
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<capacity+1;j++)
		{
			if(j<weight[i-1])
			{
				K[i][j]=K[i-1][j];
			}
			else
			{
				K[i][j]=max(K[i-1][j],(K[i-1][j-weight[i-1]]+value[i-1]));
			}
		}
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<capacity+1;j++)
		{
			cout<<K[i][j]<<"  "; 
		}
		cout<<endl;
	}
	return K[n][capacity];
}

int main()
{
	int n,i,weight[N],value[N],result,capacity;
	cout<<"\nEnter the number of items - ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the weight of item "<<i+1<<" - ";
		cin>>weight[i];
		cout<<"\nEnter the value of item "<<i+1<<" - ";
		cin>>value[i];
	}
	cout<<"\nEnter the capacity of knapsack - ";
	cin>>capacity;
	result = knapsack_function(n,weight,value,capacity);
	cout<<"\nMaximum value of knapsack is "<<result<<endl;
	return 0;
}
