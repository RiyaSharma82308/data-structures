// place the elements in correct position (arr[i]=i) else arr[i]=-1 if i isnt present
#include<bits/stdc++.h>
using namespace std;
void fix(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1 && arr[i]!=i)
        {
            int a=arr[i];
            arr[i]=arr[a];
            arr[a]=a;
            i--;
        }
    }
}
int main()
{
    int arr[] = { 19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4 };
    int n=sizeof(arr)/sizeof(arr[0]);
    fix(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
// -1 1 2 3 4 -1 6 -1 -1 9 