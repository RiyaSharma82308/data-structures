# include<bits/stdc++.h>
using namespace std;
int second(int arr[],int n,int key,int s,int end)
{
    int ans=-1;
    int mid=(s+end)/2;
    if(s>end)
    {
        return -1;
    }
    if(arr[mid]==key && (key<arr[mid+1] || mid==n-1))
    {
        return mid;
    }
    if(arr[mid]>key)
    {
        return second(arr,n,key,s,mid-1);
    }
    else 
    {
        return second(arr,n,key,mid+1,end);
    }
    return ans;
}
int first(int arr[],int n,int key,int s,int end)
{
    int ans=-1;
    int mid=(s+end)/2;
    if(s>end)
    {
        return -1;
    }
    if(arr[mid]==key && (arr[mid-1]<key || mid==0))
    {
        return mid;
    }
    else if(arr[mid]<key)
    {
        return first(arr,n,key,mid+1,end);
    }
    else
    {
        return first(arr,n,key,s,mid-1);
    }
    return ans;
}
pair<int,int> func(int arr[],int n,int key)
{
    pair<int,int>p;
    p.first=first(arr,n,key,0,n-1);
    p.second=second(arr,n,key,0,n-1);
    return p;
}
int main()
{
    int arr[5]={3,3,3,3,3};
    pair<int,int>p;
    p=func(arr,5,3);
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p.second-p.first+1;
    
}