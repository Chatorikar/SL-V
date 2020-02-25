#include<iostream>
#include<string.h>
using namespace std;

struct temp 
{ 
  int min; 
  int max; 
};   

bool check_increasing_sorted(int a[],int n)
{
	if(n==1 || n==2)
	{
		return true;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]<a[i])
			return false;
	}
	return true;
}

bool check_decreasing_sorted(int a[],int n)
{
	if(n==1 || n==2)
	{
		return true;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]>a[i])
			return false;
	}
	return true;
}
	
struct temp getMinMax(int arr[],int first,int last) 
{ 
	struct temp minmax,left,right;        
  	int mid; 
  
  	if(first==last) 
  	{ 
     	minmax.max = arr[first]; 
     	minmax.min = arr[first];      
     	return minmax; 
  	}     
  	
  	if (last==first + 1) 
  	{   
     	if (arr[first]>arr[last])   
     	{ 
        	minmax.max = arr[first]; 
        	minmax.min = arr[last]; 
     	}   
     	else
     	{ 
        	minmax.max = arr[last]; 
        	minmax.min = arr[first]; 
     	}   
     	return minmax; 
  	} 
    
  	mid = (first + last)/2;   
  	left = getMinMax(arr, first, mid); 
  	right = getMinMax(arr, mid+1, last);   
   
  	if (left.min < right.min) 
    	minmax.min = left.min; 
  	else
    	minmax.min = right.min;      
 	
  	if (left.max > right.max) 
    	minmax.max = left.max; 
  	else
   	 	minmax.max = right.max;      
   
  	return minmax; 
} 

int main() 
{ 
  	int arr[1000],n,i;
  	bool x;
  	cout<<"\nEnter the number of elements - ";
  	cin>>n;
  	for(i=0;i<n;i++)
  	{
  		cout<<"\nEnter element "<<i+1<<" - ";
  		cin>>arr[i];
  	}
  	cout<<"\nGiven Array - ";
  	for(i=0;i<n;i++)
  	{
  		cout<<arr[i]<<" ";
  	}
  	if(arr[0]>arr[1])
  	{
  		x=check_decreasing_sorted(arr,n);
  		if(x==false)
  		{
  			cout<<"\nDivide and conquer applied\n";
  			struct temp minmax = getMinMax(arr, 0, n-1); 
  			cout<<"\nMinimum element is "<<minmax.min; 
 			cout<<"\nnMaximum element is "<<minmax.max;
 			cout<<"\n"; 
  		}
  		else
  		{
  			cout<<"\nMinimum element is "<<arr[n-1]; 
 			cout<<"\nnMaximum element is "<<arr[0];
 			cout<<"\n"; 
 	 	}
  	}
  	else
  	{
  		x=check_increasing_sorted(arr,n);
  		if(x==false)
  		{
  			cout<<"\nDivide and conquer applied\n";
  			struct temp minmax = getMinMax(arr, 0, n-1); 
  			cout<<"\nMinimum element is "<<minmax.min; 
 			cout<<"\nnMaximum element is "<<minmax.max;
 			cout<<"\n"; 
  		}
  		else
  		{
  			cout<<"\nMinimum element is "<<arr[0]; 
 			cout<<"\nnMaximum element is "<<arr[n-1];
 			cout<<"\n"; 
  		}
  	}
  	return 0; 
} 
