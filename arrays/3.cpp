// to search an element in sorted and rotated array
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
int search(int arr[],int s , int e,int key)
{
    if(s>e) return -1;
    int mid=(s+e)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key)
    {
        int a=search(arr,s,mid-1,key);
    }
    else if(arr[mid]<key && mid !=0)
    {
        int a=search(arr,mid+1,e,key);
    }
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=11;
    int pivot = find_pivot(arr,0,n-1);
    if(key >= arr[0])
    {
        int a=search(arr,0,pivot,key);
        cout<<a<<endl;
    }
    else if( key <=arr[n-1])
    {
        int a=search(arr,pivot+1,n-1,key);
        cout<<a<<endl;
    }
}