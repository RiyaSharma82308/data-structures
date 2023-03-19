/////prefix to infix
#include<stdio.H>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char arr[]
};
int isempty(struct stack* st)
{
    if(st->top==-1) return 1;
    return 0;
}

int isoperand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') return 1;
    return 0;
}
int main()
{
    char* prefix="*-A/BC-/AKL";
    struct stack* st=(struct stack*) malloc(sizeof(struct stack));
    st->size=100;
    st->top=-1;
    st->arr=(char*)malloc(sizeof(char[100])*st->size);
    // for(int i=strlen(prefix)-1;i>=0;i--)
    // {
    //     if(isoperand(prefix[i]))
    //     {
    //         char s[]="";
    //         s=strncat(s,&prefix[i],1);
    //         push(st,s);
    //     }
        // else
        // {
        //     char* s="";
        //     char x=pop(st);
        //     s=strncat(s,&x,1);
        //     s=strncat(s,&prefix[i],1);
        //     x=pop(st);
        //     s=strncat(s,&x,1);
        //     push(st,s);
        // }
    }
}