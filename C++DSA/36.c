#include<stdio.h>
int gcd(int n,int k)
{
    if(k==0) return n;
    return gcd(k,n%k);
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int r=2;
    int l=1;
    int diff=l-r;
    int left=1;
    int right=4;
    if(diff>0)
    {
        for(int i=0;i<gcd(n,diff);i++)
        {
            int temp=arr[i];
            int j=i;
            while(1)
            {
                int k=j+diff;
                if(k>=n) k=k-n;
                if(k==i) break;
                arr[j]=arr[k];
                j=k;
            }
            arr[j]=temp;
        }
        int arr2[n+1];
        arr2[0]=0;
        for(int i=1;i<=n;i++)
        {
            arr2[i]=arr[i-1]+arr2[i-1];
        }
        printf("%d",arr2[right+1]-arr2[left]);
    }
    else if(diff<0)
    {
        diff=diff*(-1);
        for(int i=0;i<n/2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=temp;
        }
        for(int i=0;i<gcd(n,diff);i++)
        {
            int temp=arr[i];
            int j=i;
            while(1)
            {
                int k=j+diff;
                if(k>=n) k=k-n;
                if(k==i) break;
                arr[j]=arr[k];
                j=k;
            }
            arr[j]=temp;
        }
        int arr2[n+1];
        arr2[0]=0;
        for(int i=1;i<=n;i++)
        {
            arr2[i]=arr[i-1]+arr2[i-1];
        }
        printf("%d",arr2[right+1]-arr2[left]);
    }
    else
    {
        int arr2[n+1];
        arr2[0]=0;
        for(int i=1;i<=n;i++)
        {
            arr2[i]=arr[i-1]+arr2[i-1];
        }
        printf("%d",arr2[right+1]-arr2[left]);
    }
}