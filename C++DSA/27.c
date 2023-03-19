#include<stdio.h>
int part(int l,int h,char arr[],char r,char w,char b)
{
    int pivot=arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[l];
    arr[l]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int l,int h,char arr[],char r,char w,char b)
{
    if(l<h)
    {
        int pivot=part(l,h,arr,r,w,b);
        quicksort(l,pivot-1,arr,r,w,b);
        quicksort(pivot+1,h,arr,r,w,b);
    }
}
int main()
{
    char r='a';
    char w='b';
    char b='c';
    char arr[10]={r,w,b,r,w,b,r,w,b,r};
    quicksort(0,9,arr,r,w,b);
    for(int i=0;i<10;i++){
        if(arr[i]==r)
        {
            printf("%s ","red");
        }
        else if(arr[i]==w)
        {
            printf("%s ","white");
        }
        else if(arr[i]==b)
        {
            printf("%s ","blue");
        }    
    }
}