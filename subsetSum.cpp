#include<iostream>
using namespace std;

int cnt = 0;
int isSubsetSum(int arr[], int n, int sum)
{
    //cout<<"n:"<<n<<" sum:"<<sum<<endl;
   if (sum==0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;

   // skippin elem[n-1] > sum
   if (arr[n-1] > sum)
   {
     //cout<<"n:"<<n-1<<" sum:"<<sum<<" skip"<<endl;
     return isSubsetSum(arr, n-1, sum);
   }
      //incl last elem
      //excl last elem
   return isSubsetSum(arr, n-1, sum) ||
                        isSubsetSum(arr, n-1, sum-arr[n-1]);
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  cout<<isSubsetSum(set, n, sum)<<endl;

  return 0;
}
