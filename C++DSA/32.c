#include<stdio.h>
int findpivot(int arr[],int low,int high)
{
    if(low>high) return high;
    int mid=(low+high)/2;
    if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]) return mid;
    else if(arr[mid]>arr[0]) return findpivot(arr,mid+1,high);
    else return findpivot(arr,low,mid);
}
int findele(int arr[],int low,int high,int ele)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==ele) return mid;
    else if(arr[mid]>ele) return findele(arr,low,mid-1,ele);
    else return findele(arr,mid+1,high,ele);
}
int main()
{
    int arr[]={7,8,9,10,11,12,1,2,3};
    int piv=findpivot(arr,0,8);
    int a;
    int ele=12;
    if(ele>=arr[piv] && ele<=arr[8])
    {
        a=findele(arr,piv,8,ele);
    }
    else a=findele(arr,0,piv-1,ele);
    printf("%d",a);
}