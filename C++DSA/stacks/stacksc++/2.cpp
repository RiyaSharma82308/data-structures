// postfix to infix
#include<bits/stdc++.h>
using namespace std;
int isoperand(char c)
{
    if(c>='a'&& c<='z' || c>='A' && c<='Z') return 1;
    return 0;
}
int main()
{
    string postfix="abc++";
    stack<string>st;
    for(int i=0;i<postfix.length();i++)
    {
        if(isoperand(postfix[i]))
        {
            st.push(string(1,postfix[i]));
        }
        else
        {
            string a=st.top();
            st.pop();
            string b=st.top();
            st.pop();
            string s='('+b+postfix[i]+a+')';
            st.push(s);
        }
    }
    cout<<st.top();
}