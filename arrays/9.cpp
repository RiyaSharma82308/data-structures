// Rearrange positive and negative numbers in O(n) time and O(1) extra space
#include<bits/stdc++.h>
using namespace std;
void separate_arrange(int arr[],int n)
{
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int pos=i+1;
    int neg=0;
    while(neg<pos && arr[neg]<0 && pos<n)
    {
        swap(arr[pos],arr[neg]);
        pos++;
        neg+=2;
    }
}
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    separate_arrange(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
//  4   -3    5   -1    6   -7    2    8    9