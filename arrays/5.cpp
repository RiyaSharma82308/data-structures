// Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
#include<bits/stdc++.h>
using namespace std;
int maxsum(int arr[],int n)
{
    int array_sum=0;
    int curr_sum=0;
    for(int i=0;i<n;i++)
    {
        array_sum+=arr[i];
        curr_sum+=i*arr[i];
    }
    int maxi=0;
    for(int i=1;i<n;i++)
    {
        curr_sum=curr_sum + array_sum - n*arr[n-i];
        if(curr_sum > maxi) maxi=curr_sum;
    }
    return maxi;
}
int main()
{
    int arr[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum=maxsum(arr,n);
    cout<<max_sum;
}