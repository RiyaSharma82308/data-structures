#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char* arr;
};
void push(struct stack* st,int ele)
{
    st->top++;
    st->arr[st->top]=ele;
}
int pop(struct stack* st)
{
    int x=st->arr[st->top];
    st->top--;
    return x;
}
void reverse(struct stack* st)
{
    while(st->top!=-1)
    {
        printf("%c",st->arr[st->top]);
        st->top--;
    }
    printf(" ");
}
int main()
{
    int n=3;
    char sentence[n][100];
    for(int i=0;i<n;i++)
    {
        char s[100];
        scanf("%s",s);
        strcpy(sentence[i],s);
    }
    for(int i=0;i<n;i++)
    {
        struct stack* st=(struct stack*)malloc(sizeof(struct stack));
        st->size=strlen(sentence[i]);
        st->top=-1;
        st->arr=(char*)malloc(sizeof(char) * st->size);
        if(sentence[i]==" ") continue;
        else
        {
            for(int j=0;j<=strlen(sentence[i]);j++)
            {
                push(st,sentence[i][j]);
            }
            reverse(st);
        }
    }
}