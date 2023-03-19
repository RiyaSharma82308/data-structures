#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[][100]={"hellow","hi","there"};
    for(int i=0;i<3;i++)
    {
        printf("%s ",str[i]);
    }
    char s[]={'h','o'};
    for(int i=0;i<2;i++)
    {
        printf("%c ",s[i]);
    }
}