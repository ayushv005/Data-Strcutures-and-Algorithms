using namespace std;
int t1, t2;
//int M = 1000000007;
long long unsigned int lookup[21] = {0};
long long unsigned int fibMod(int n)
{
    if (n==1)
        return t1;
    if (n==2)
        return t2;
    if (n==3)
        return t1+t2*t2;
    if (lookup[n]!=0)
        return lookup[n];
    return lookup[n] = fibMod(n-2) + fibMod(n-1)*fibMod(n-1);
}

int main() {

    int n;
    cin>>t1>>t2>>n;
    cout<<fibMod(n);


    return 0;
}
