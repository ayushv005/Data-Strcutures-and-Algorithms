//princess & dragon
// 1 and 2 allowed; 3 = destination; startPos = lowest left

#include<iostream>
using namespace std;
#define N 4

int itrx=N-1,itry=N-1,cnt = -1;
// to check out-of-bounds for maze[][]
bool isSafe(int maze[N][N],int x, int y)
{                                                 //changes made
  if(x>=0 && y>=0 && x<N && y<N && (maze[x][y]==1 || maze[x][y]==2))
    return true;
  return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{ // if N-1,N-1 is the destination
  if(x==itrx && y==itry)  //changes made
  {
    sol[x][y] = 1;
    cnt++;
    return true;
  }

  if(isSafe(maze,x,y)==true)
  {
    cnt++;
    sol[x][y] = 1;
    //changes made (x+1)-->(x-1) : 'x' ois is vertical compo
    if(solveMazeUtil(maze,x-1,y,sol)==true)
      return true;
    if(solveMazeUtil(maze,x,y+1,sol)==true)
      return true;

    cnt--;
    sol[x][y] = 0;
    return false;
  }
  return false;
}

void solveMaze(int maze[N][N])
{
  int sol[N][N] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };
  //0,0 is the start pos of the rat
  if(solveMazeUtil(maze,N-1,0,sol)==false)  //changes made
    cout<<-1<<endl;
  else
    cout<<cnt<<endl;

  for (int i=0;i<N;i++)
  {
    for (int j=0;j<N;j++)
      cout<<sol[i][j]<<"\t";
    cout<<endl;
  }

  return;
}

int main()
{
  int maze[N][N] =
  {
    {1,1,0,1},
    {0,2,3,1},
    {1,1,1,0},
    {1,0,1,1},
  };

  for (int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(maze[i][j]==3)
      {
        itrx = i;
        itry = j;
      }
    }
  }

  solveMaze(maze);
  return 0;
}
