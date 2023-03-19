// Rearrange positive and negative numbers with constant extra space
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = { 5, 5, -3, 4, -8, 0, -7, 3, -9, -3, 9, -2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>=0)
        {
            int j=i+1;
            while(arr[j]>=0)
            {
                j++;
            }
            if(j==n)
            {
                break;
            }
            else
            {
                int temp=arr[j];
                for(int p=j;p>i;p--)
                {
                    arr[p]=arr[p-1];
                }
                arr[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}