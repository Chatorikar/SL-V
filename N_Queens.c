#include <stdio.h>
#include<math.h>
#include<stdbool.h>
#include <stdlib.h>
#define N 4

int x[N]={0};

void Show_All_Position()
{
  for(int i = 1 ; i <= N ;i++)
  {
    printf("\n" );
    for(int j = 1 ; j <= N ;j++)
    {
        if(x[i] == j)
        {
          printf("Q ");
        }
        else
          printf("- " );
    }
  }
}

bool place(int Queen_No , int i)
{
  for(int row_no = 1; row_no <= Queen_No ; row_no++)
  {
    if(x[row_no] == i || ( abs(x[row_no]-i) == abs(row_no-Queen_No)) )
    {
      return false;
    }
  }
    return true;
}


void N_Queens(int Queen_No , int size_of_board)
{
  int i;
  for(i = 1 ; i <= size_of_board ; i++)
  {
    if(place(Queen_No,i))
    {
      x[Queen_No]=i;

      if(Queen_No==size_of_board)
      {
        Show_All_Position();
        printf("\n");
      }
      else
      {
          N_Queens(Queen_No+1,size_of_board);
      }
    }
  }
}

int main()
{
  int size_of_board=4;

  // printf("\nEnter Number of Queens : " );
  // scanf("%d"&size_of_board );

  N_Queens(1,size_of_board);
  return 0;
}
