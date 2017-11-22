#include<iostream>
using namespace std;

int main()
{
  int t,i,j,k,temp;
  int a[100][100],b[100][100],n[100],res[100];
  cin>>t;

  for (i=0;i<t;i++)
  {
    cin>>n[i];
    for (j=0;j<n[i];j++)
    {
      cin>>a[i][j];
      b[i][j]=0;
    }
  }

  for(i=0;i<t;i++)
  {
    for(j=0;j<n[i];j++)
    {
      temp = a[i][j];

      for(k=0;k<n[i];k++)
      {
        if(temp == a[i][k])
        {
          b[i][j]++;
        }
      }
    }
  }

  for(i=0;i<t;i++)
  {
    temp = -1;
    for(j=0;j<n[i];j++)
    {
      if(b[i][j]>n[i]/2)
      {
        temp = a[i][j];
      }x
    }
    if(temp!=-1)
    {
      cout<<temp<<endl;
    }
    else
    {
      cout<<"NO Majority Element"<<endl;
    }
  }

  /*for (i=0;i<t;i++)
  {
    for (j=0;j<n[i];j++)
    {
      cout<<b[i][j]<<"\t";
    }
    cout<<endl;
  }*/

  return 0;
}
