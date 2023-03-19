#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ind=0;
int row=5;
int col=4;
void func(int i,int j,int arr[5][4],char* ans)
{
    if(i>=row || j>=col || arr[i][j]==0)
    {