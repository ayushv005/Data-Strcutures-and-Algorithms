#include<iostream>
#include<string>
using namespace std;

int main()
{
  string str,a;
  cin>>str;
  int i,cnt=1,temp=0;
  int n= str.length();

  for (i=0;i<n;i++)
  {
      a+=str[i];
      if(i+1<n)
      {
        while(str[i]==str[i+1])
        {
          cnt++;
          i++;
        }
      }
      a+= cnt + 48;
      cnt=1;
  }

  if(n<=a.length())
    cout<<str<<endl;
  else
    cout<<a<<endl;

  return 0;
}
