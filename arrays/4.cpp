// Find if there is a pair with a given sum in the rotated sorted Array
#include<bits/stdc++.h>
using namespace std;
int find_pivot(int arr[],int start,int end)
{
    if(start > end)
    {
        return -1;
    }
    if(start==end) return start;
    int mid=(start+end)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] && mid<end)
    {
        return mid;
    }
    else if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1] && mid>start)
    {
        return mid-1;
    }
    else if(arr[mid]>=arr[0] && mid >0)
    {
        return find_pivot(arr,mid+1,end);
    }
    else
    {
        return find_pivot(arr,start,mid-1);
    }
}
int findsum(int arr[],int sum,int n)
{
    int pivot=find_pivot(arr,0,n-1);
    int left=pivot;
    int right=pivot+1;
    while(left!=right)
    {
        if(arr[left]+arr[right]==sum)
        {
            cout<<arr[left]<<" "<<arr[right]<<endl;
            return 1;
        }
        else if(arr[left]+arr[right]>sum)
        {
            left=(n+left-1)%n;
        }
        else 
        {
            right=(right+1) % n;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int x=16;
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=findsum(arr,x,n);
    cout<<a;
}