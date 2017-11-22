#include<iostream>
#include<string>
using namespace std;

void isString(string p,string q,int n)
{
  for(int i=0;i<=n;i++)
  {
    int j;
    for(j=0;j<n;j++)
    {
      if(p[i+j]!=q[j])
        break;
    }
    if(j==n)
    {
      cout<<"true"<<endl;
      return;
    }
  }
  cout<<"false"<<endl;
  return;
}

int main()
{
  string a,b;
  cin>>a>>b;
  int n=a.length();
  int m=b.length();
  if(n==m && n>0)
  {
    string a2 = a + a;
    //cout<<a2<<endl;
    isString(a2,b,n);
  }
  else
  {
    cout<<"false"<<endl;
  }

  return 0;
}
