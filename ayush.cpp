#include <bits/stdc++.h>
using namespace std;

void check(int arr[])
{
  int count = 0;
  for(int i=0;i<58;i++)
  {
    if(arr[i]!=2 && arr[i]!=0)
    {
      if(arr[i]!=1)
      {
        cout<<"False";
      }
      else
      {
        count++;
        if(count>1)
        {
          cout<<"False";
        }
      }
    }
  }
  cout<<"True";
}

int main()
{
  string str;
  getline(cin,str);
  int n = str.length();
  int arr[58],i;

  for(i=0;i<58;i++)
  {
    arr[i]=0;
  }
  for (i=0;i<n;i++)
  {
    if(str[i]!=' ')
    {
      arr[int(str[i])-65]++;
    }
  }

  // for(i=0;i<58;i++)
  // {
  //   cout<<arr[i]<<"\t";
  // }


  check(arr);

  return 0;
}
