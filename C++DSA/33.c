#include<stdio.h>
int pivot(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1]) return i;
    }
}
int findpair(int arr[],int l,int h,int n,int sum)
{
    while(l!=h)
    {
        if(arr[l]+arr[h]==sum) return 1;
        else if(arr[l]+arr[h]>sum) h=(n+h-1)%n;
        else l=(l+1)%n;
    }
    return 0;
}
int main()
{
    int arr[]={5,6,7,8,1,2,3};
    int n=7;
    int a=pivot(arr,n);
    int b=findpair(arr,a,(a+1)%n,n,20);
    printf("%d",b);
}