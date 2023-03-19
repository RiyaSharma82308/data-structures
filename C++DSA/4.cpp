# include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long int arr[N];
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int l,r,d;
        cin>>l>>r>>d;
        arr[l]+=d;
        arr[r+1]-=d;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i]+=arr[i-1];
    }
    int max=-1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<max;
}