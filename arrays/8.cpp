//Given an array of n elements. Our task is to write a program to rearrange the array such that elements at even positions are greater than all elements before it and elements at odd positions are less than all elements before it.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]= {1, 2, 1, 4, 5, 6, 8, 8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back(arr[i]);
    }
    sort(vec.begin(),vec.end());
    int start=0;
    int end=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(i%2!=0)
        {
            arr[i]=vec[end--];
        }
        else
        {
            arr[i]=vec[start++];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
// 4 5 2 6 1 8 1 8 