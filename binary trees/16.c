// print postorder traversal by inorder and preorder traversal given
#include<stdio.h>
#include<stdlib.h>
int preindex=0;
int findindex(int arr[],int pre[],int start,int end,int preindex)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==pre[preindex]) return i;
    }
    return -1;
} 
void printPost(int arr[],int pre[],int start,int end)
{
    if(start>end) return;
    int index=findindex(arr,pre,start,end,preindex++);
    printPost(arr,pre,start,index-1);
    printPost(arr,pre,index+1,end);
    printf("%d ",arr[index]);
}
int main()
{
    int arr[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    printPost(arr, pre, 0, len - 1);
}