// Reorder an array according to given indexes
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={10,11,12};
    int index[]={1,0,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        while(index[i]!=i)
        {
            int a=index[index[i]];
            int b=arr[index[i]];
            arr[index[i]]=arr[i];
            index[index[i]]=index[i];
            arr[i]=b;
            index[i]=a;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  "<<index[i]<<endl;
    }
}