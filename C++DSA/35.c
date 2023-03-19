/////// right rotating the array
#include<stdio.h>
int gcd(int n,int k)
{
    if(k==0) return n;
    return gcd(k,n%k);
}
int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<n/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<gcd(n,k);i++)
    {
        int temp=arr[i];
        int j=i;
        while(1)
        {
            int x=j+k;
            if(x>=n) x=x-n;
            if(x==i) break;
            arr[j]=arr[x];
            j=x;
        }
        arr[j]=temp;
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<n/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}