#include<stdio.h>
int main()
{
    int arr[]={10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int currsum=0;
    int arraysum=0;
    for(int i=0;i<n;i++)
    {
        arraysum+=arr[i];
        currsum+=i*arr[i];
    }
    int m=currsum;
    for(int i=1;i<n;i++)
    {
        currsum=currsum+arraysum-(n*arr[n-i]);
        if(currsum>m) m=currsum;
    }
    printf("%d",m);
}