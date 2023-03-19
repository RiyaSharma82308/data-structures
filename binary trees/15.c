#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        arr1[i]=a;
    }
    int arr2[q];
    int arr3[q];
    for(int i=0;i<q;i++)
    {
        int a;
        scanf("%d",&a);
        arr2[i]=a;
        arr3[i]=a;
    }
    for(int i=0;i<q-1;i++)
    {
        for(int j=i+1;j<q;j++)
        {
            if(arr2[j]>arr2[i])
            {
                int temp=arr2[j];
                arr2[j]=arr2[i];
                arr2[i]=temp;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int x=0;
        for(int j=0;j<n;j++)
        {
            if(arr2[i]<=arr1[j])
            {
                printf("hi\n");
                x=1;
                arr1[j]=arr1[j]-arr2[i];
                for(int y=0;y<q;y++)
                {
                    if(arr3[y]==arr2[i])
                    {
                        printf("hiiiiiiiiii\n");
                        arr3[y]=j+1;
                        printf("values canged %d\n",arr3[y]);
                        break;
                    }
                }
                break;
            }
        }
        if(x==0)
        {
            for(int y=0;y<q;y++)
            {
                if(arr3[y]==arr2[i])
                {
                    printf("here\n");
                    arr3[y]=0;
                    break;
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        printf("%d ",arr3[i]);
    }
}