#include<iostream>
using namespace std;

int partition(int a[], int low, int high)
{
  int pivot = a[high];
  int i = low-1;
  int j,temp;
  for (int j=low;j<=high;j++)
  {
    if(a[j]<=a[high])
    { //if pivot>elem: postion that elem at leftmost pos
      i++;
      temp = a[j];//swap
      a[j] = a[i];
      a[i] = temp;
    }
  }
  return i;
}

void quickSort(int a[], int low, int high)
{
  if (low<high)
  {
    int pi = partition(a,low,high);

    quickSort(a,low,pi-1);
    quickSort(a,pi+1,high);
  }
}

int main()
{
  int i,n;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];

  quickSort(a,0,n-1);

  for(i=0;i<n;i++)
    cout<<a[i]<<"\t";
  cout<<endl;
}
