// Find the Rotation Count in Rotated Sorted array
#include<bits/stdc++.h>
using namespace std;
int binarysearch(int arr[],int start, int end)
{
    if(start > end) return -1;
    int mid=(start+end)/2;
    if(arr[mid]<arr[mid-1]) return mid;
    else if(arr[mid] > arr[0])
    {
        return binarysearch(arr,mid+1,end);
    }
    else return binarysearch(arr,start,mid-1);
}
int main()
{
    int arr[] = {7, 9, 11, 12, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=binarysearch(arr,0,n-1);
    cout<<a;
}