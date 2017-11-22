#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n,i,j;
  cin>>n;
  int a[n][n];

  int temp1,temp2,temp3;

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }

  for(i=0;i<n-1;i++)
  {
    for(j=i;j<n-i-1;j++)
    {
      temp1 = a[j][n-i-1];
      a[j][n-i-1] = a[i][j];
      temp2 = a[n-i-1][n-j-1];
      a[n-i-1][n-j-1] = temp1;
      temp3 = a[n-j-1][i];
      a[n-j-1][i] = temp2;
      a[i][j]=temp3;
    }
}

    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        cout<<a[i][j]<<"\t";
      }
      cout<<endl;
    }


  return 0;
}
