#include<stdio.h>
int main()
{
    int arr[3][3]={{1,4,2},{9,6,7},{8,3,5}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mini=j;
            for(int k=j+1;k<3;k++)
            {
                if(arr[i][k]<arr[i][mini])
                {
                    mini=k;
                }
            }
            int temp=arr[i][mini];
            arr[i][mini]=arr[i][j];
            arr[i][j]=temp;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mini=j;
            for(int k=j+1;k<3;k++)
            {
                if(arr[k][i]<arr[mini][i])
                {
                    mini=k;
                }
            }
            int temp=arr[mini][i];
            arr[mini][i]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}