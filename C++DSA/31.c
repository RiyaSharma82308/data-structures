///////  juggling algorithm
#include<stdio.h>
int gcd(int n,int d)
{
    if(d==0) return n;
    else return gcd(d,n%d);
}
void rotate(int arr[],int n,int d)
{
    d=d%n;
    int g=gcd(n,d);
    // printf("%d\n",g);
    int a=0;
    while(a<g)
    {
        int temp=arr[a];
        int i=a;
        while(1)
        {
            int k=i+d;
            if(k>=n) k=k-n;
            if(k==a) break;
            arr[i]=arr[k];
            i=k;
        }
        arr[i]=temp;
        ++a;
    }
}
int main()
{
    int arr[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i=0;i<12;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    rotate(arr,12,2);
    for(int i=0;i<12;i++)
    {
        printf("%d ",arr[i]);
    }
}