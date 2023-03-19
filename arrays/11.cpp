// Move all zeroes to end of array
#include<bits/stdc++.h>
using namespace std;
// int main()
// {
//     int arr[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     vector<int>vec;
//     int count=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==0) count++;
//         else
//         {
//             vec.push_back(arr[i]);
//         }
//     }
//     for(int i=0;i<count;i++)
//     {
//         vec.push_back(0);
//     }
//     for(int i=0;i<n;i++)
//     {
//         arr[i]=vec[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }


int main()
{
    int arr[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[count++]=arr[i];
        }
    }
    for(int i=count;i<n;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}