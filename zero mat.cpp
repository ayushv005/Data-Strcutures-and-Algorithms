#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,j,n;
  cin>>n;
  int a[n][n];
  bool row[n],col[n];

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>a[i][j];

      if(a[i][j]==0)
      {
        row[i]=true;
        col[j]=true;
      }
    }
  }

  for(i=0;i<n;i++)
  {
    if(row[i])
    {
      for(j=0;j<n;j++)
      {
        a[i][j]=0;
      }
    }
    if(col[i])
    {
      for(j=0;j<n;j++)
      {
        a[j][i]=0;
      }
    }
  }

  for (i=0;i<n;i++)
  {
    for (j=0;j<n;j++)
    {
      cout<<a[i][j]<<"\t";
    }
    cout<<endl;
  }


  return 0;
}
