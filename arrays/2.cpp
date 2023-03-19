// rotate array to left by d positions using reverse algorithm
#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int start,int end)
{
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void rotate(int arr[],int d,int n)
{
    if(d==0) return;
    d=d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
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