#include<iostream>
#include<string>
using namespace std;

void solve(string a, string b)
{
  int n=a.length();
  int m=b.length();
  int i=0,j=0,count=0;

  while(i<n && j<m)
  {
    if(a[i]==b[j])
    {
      i++;
      j++;
    }
    else
    {
      count++;
      //cout<<count<<endl;
      i++;
    }
  }
  if (count>1)
    cout<<"false"<<endl;
  else
    cout<<"true"<<endl;
}

int main()
{
  int i,count=0;
  string a,b;
  cin>>a>>b;
  int n=a.length();
  int m=b.length();

  if(n==m)
  {
    for(i=0;i<n;i++)
    {
      if(a[i]!=b[i])
        count++;
    }
    if(count>1)
      cout<<"false"<<endl;
    else
      cout<<"true"<<endl;
  }
  else if(abs(n-m)>1)
    cout<<"false"<<endl;
  else{
    if (n-m==1)
      solve(a,b);
    if(m-n==1)
      solve(b,a);

  }


  return 0;
}
