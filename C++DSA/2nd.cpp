////prefix computation having left and right place specifies
# include<iostream>
using namespace std;
const int N=1e7+10;
int arr1[N];
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr1[i]=arr1[i-1]+arr[i];
    }
    int L,R;
    cin>>L>>R;
    cout<<arr1[R]-arr1[L-1];
}