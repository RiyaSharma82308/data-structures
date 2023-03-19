// Minimum swaps required to bring all elements less than or equal to k together
#include<bits/stdc++.h>
using namespace std;
int min_swaps(int arr[],int n,int k)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k) count++;
    }
    int bad=0;
    for(int i=0;i<count;i++)
    {
        if(arr[i]>k) bad++;
    }
    int ans=bad;
    for(int i=0, j=count;j<n;i++,j++)
    {
        if(arr[i]>k) bad--;
        if(arr[j]>k) bad++;
        ans=min(ans,bad);
    }
    return ans;
}
int main()
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k=5;
    int a=min_swaps(arr,n,k);
    cout<<a;
}