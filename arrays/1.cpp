// Program for array rotation by juggling algorithm
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

void rotate(int arr[],int d,int n)
{
    int _gcd_=gcd(n,d);
    for(int i=0 ; i<_gcd_ ; i++)
    {
        int temp=arr[i];
        int j=i;
        while(true)
        {
            int k=(j+d)%n;
            if(k==i) break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }
}
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    int d=2;
    int n=sizeof(arr) / sizeof(arr[0]);
    rotate(arr,d,n);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
}