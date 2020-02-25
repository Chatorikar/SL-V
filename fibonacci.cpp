#include<bits/stdc++.h>
using namespace std;

int fibonacci(int a[],int n)
{
	a[0]=0;
	a[1]=1;
	if(a[n]!=-1)			
		return a[n];
	else
	{
		a[n]=fibonacci(a,n-1)+fibonacci(a,n-2);
		return a[n];
	}
}

int main()
{
	int n;
	cout<<"Enter the value of n - ";
	cin>>n;
	int a[n+1];
	for(int i=0;i<=n;i++)
		a[i]=-1;
	for(int i=0;i<n;i++)
		cout<<fibonacci(a,i)<<" ";
	cout<<endl;
	return 0;
}
