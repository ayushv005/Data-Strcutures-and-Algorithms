#include<iostream>
using namespace std;

bool isSafe(int board[][],int row, int col, int n)
{
  int i,j;
  for(i=0;i<col;i++)
    if(board[row][i]) //up and down check
      return false;

  for(i=row, j=col; i>=0 && j>=0; i--, j--)
    if(board[row][i]) // '\' up diagonal
      return false;

  for(i=row, j=col; j>=0 && i<n; i++, j--)
    if(board[row][i]) // '/' up diagonal
      return false;

  return true;
}


bool nQueen(int board[][], int col, int n)
{
  if(col >= n)
    return true;

  for (int i=0;i<n;i++)
  {
    if(isSafe(board,i,col,n)==true)
    {
      board[i][col]=1;
      if(nQueen(col+1))
        return true;

      board[i][col]=0;
    }
  }
  return false;
}

int main()
{
  int n;
  cin>>n;
  int board[n][n];

  for (int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      board[i][j] = 0;
  }

  nQueen(board, 0, n);
  return 0;
}
