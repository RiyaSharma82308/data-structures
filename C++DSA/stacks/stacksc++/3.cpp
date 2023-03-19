/// infix to prefix using stacks c++
#include<bits/stdc++.h>
using namespace std;
string reverse(string infix)
{
    string exp="";
    for(int i=infix.length()-1;i>=0;i--)
    {
        if(infix[i]==')')
        {
            exp.push_back('(');
        }
        else if(infix[i]=='(')
        {
            exp.push_back(')');
        }
        else
        {
            exp.push_back(infix[i]);
        }
    }
    return exp;
}
int isoperand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') return 1;
    return 0;
}
int prec(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/' || ch=='%') return 2;
    else if(ch=='^') return 3;
    else  return 0;
}
int main()
{
    string infix="(A-B/C)*(A/K-L)";
    infix='('+infix+')';
    string exp=reverse(infix);
    cout<<exp<<endl;
    string prefix="";
    stack<char>st;
    for(int i=0;i<exp.length();i++)
    {
        // cout<<exp[i]<<endl;;
        if(isoperand(exp[i]))
        {
            prefix.push_back(exp[i]);
        }
        else if(exp[i]=='(') 
        {
            st.push('(');
        }
        else if(exp[i]==')')
        {
            while(st.top()!='(' && !st.empty())
            {
                prefix.push_back(st.top());
                st.pop();
            }
            if(st.top()=='(') 
            {
                st.pop();
            }
            else 
            {
                cout<<"invalid expression";
                break;
            }
        }
        else
        {
            while(prec(exp[i])<=prec(st.top()) && !st.empty())
            {
                prefix.push_back(st.top());
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty())
    {
        prefix.push_back(st.top());
        st.pop();
    }
    cout<<prefix<<endl;
    prefix=reverse(prefix);
    // reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}
*-A/BC-/AKL