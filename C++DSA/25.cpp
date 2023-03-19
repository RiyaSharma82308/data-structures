///// count sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={2,1,5,4,0};
    int n=5;
    int maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        maxi=max(arr[i],maxi);
    }
    // cout<<"aaaaaaaaaa"<<endl;
    int count[100]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=maxi;i++)
    {
        count[i]+=count[i-1];
    }
    // cout<<"bbbbbbbbb"<<endl;
    int output[n];
    // cout<<"zzzzz"<<endl;
    for(int i=n-1;i>=0;i--)
    {
        // cout<<"xxxxxxxx"<<endl;
        output[--count[arr[i]]]=arr[i];
    }
    // cout<<"cccccccccc"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
    // cout<<"dddddddddd"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}