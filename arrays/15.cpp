// Double the first element and move zero to end
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int positive=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[positive]);
            positive++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}