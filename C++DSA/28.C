#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int sum_required=7;
    int i=0;
    int j=4;
    while(i<=j)
    {
        if(arr[i]+arr[j]==sum_required)
        {
            printf("%d %d",arr[i],arr[j]);
            printf("\n");
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>sum_required)
        {
            j--;
        }
        else if(arr[i]+arr[j]<sum_required)
        {
            i++;
        }
    }
}