#include<iostream>
using namespace std;

int merge(int a[], int l, int m, int r)
{
  int i,j,k,cnt=0;
  int n1 = m-l+1;
  int n2 = r-m;

  int L[n1],R[n2];

  for(i=0;i<n1;i++)
    L[i]=a[l+i];
  for(j=0;j<n2;j++)
    R[j]=a[m+1+j];

  i=j=0;k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
    {
      a[k]=R[j];
      cnt += m+1-i;
      j++;
    }
    k++;
  }

  while(i<n1)
  {
    a[k]=L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    a[k]=R[j];
    j++;
    k++;
  }
  return cnt;
}

int mergeSort(int a[], int l, int r)
{
  int cnt=0;
  if (l<r)
  {
    int m = l+(r-l)/2;

    cnt = mergeSort(a,l,m);
    cnt += mergeSort(a,m+1,r);

    cnt += merge(a,l,m,r);
  }
  return cnt;
}

int main()
{
  int i,n;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];

  int inv_cnt = mergeSort(a,0,n-1);

  //for(i=0;i<n;i++)
//    cout<<a[i]<<"\t";
  cout<<inv_cnt;
  cout<<endl;
}
