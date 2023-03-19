// Rearrange array in alternating positive & negative items with O(1) extra space 
// neg,pos,neg,pos,.........order maintained
#include<bits/stdc++.h>
using namespace std;
void fix_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i%2!=0 && arr[i]<0)
        {
            int pos=i;
            while(arr[pos]<0 && pos<n)
            {
                pos++;
            }
            if(pos==n) break;
            int temp=arr[pos];
            for(int j=pos;j>=i;j--)
            {
                if(j==i)
                {
                    arr[j]=temp;
                }
                else
                {
                    arr[j]=arr[j-1];
                }
            }
        }
        else if(i%2==0 && arr[i]>0)
        {
            int pos=i;
            while(arr[pos]>=0 && pos<n)
            {
                pos++;
            }
            if(pos==n) break;
            int temp=arr[pos];
            for(int j=pos;j>=i;j--)
            {
                if(j==i)
                {
                    arr[j]=temp;
                }
                else
                {
                    arr[j]=arr[j-1];
                }
            }
        }
    }
}
int main()
{
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    fix_array(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
// -5 5 -2 2 -8 4 7 1 8 0 