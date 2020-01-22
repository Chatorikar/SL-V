#include<bits/stdc++.h>

using namespace std;
int pass = 1;
struct test{
  int mini=INT_MAX;
  int maximum=INT_MIN;
}t;

void line()
{
  cout<<endl;
  for(int  i = 0 ; i < 50 ; i++)
  {
    cout<<"--";
  }
  cout<<endl;
}

void print(int *a , int left , int right)
{
  line();
  for(int  i = left ; i < right ; i++)
  cout<<a[i]<<" ";
  line();
}

struct test Min_Max(int *a , int left , int right , int min  , int max)
{
    cout<<"Pass "<<pass<<" : ";
    pass++;
    print(a,left,right);
    if(right-left == 0){
      struct test t;
      max = a[0];
      min = a[0];
      t.maximum = a[0];
      t.mini = a[0];
      return t;
    }
    else if(right-left == 1){

        if(a[right] >= a[left]){
          min = a[left];
          max = a[right];
        }
        else{
          max = a[left];
          min = a[right];
        }

      t.maximum = max;
      t.mini = min;
      return t;
    }

      int mid = (left+right)/2;
      // cout<<" "<<left;
      // cout<<" "<<right<<endl;
      struct test t1 = Min_Max(a,left,mid,min,max);
      struct test t2 = Min_Max(a,mid+1,right,min,max);
      struct test t3;
      if(t1.maximum > t2.maximum)
      {
        t3.maximum = t1.maximum;
      }
      else
      {
        t3.maximum = t2.maximum;
      }

      if(t1.mini < t2.mini)
      {
        t3.mini = t1.mini;
      }
      else
      {
        t3.mini = t2.mini;
      }




      return t3;





}

int main()
{
    int num=8;
    // cout<<"\nEnter the Size of Array : ";
    // cin>>num;

    int *a = new int[num];

    cout<<"\nEnter the Array : ";


    for(int i = 0 ; i < num ; i++)
    {
        // cout<<endl<<"Array["<<i<< "] :  ";
        cin>>a[i];
    }

    // for(int i = 0 ; i < num ; i++)
    //   cout<<a[i]<<" ";

    struct test temp = Min_Max(a,0 ,num , INT_MAX ,INT_MIN );
    cout<<"\n Minimum : "<<temp.mini;
    cout<<"\n Maximum : "<<temp.maximum;

// 10 3 2 5 1 6 8 4
}
