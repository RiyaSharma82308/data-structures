/// prefix to infix using c++
#include<bits/stdc++.h>
using namespace std;
int isoperand(char ch)
{
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') return 1;
    return 0;
}
int main()
{
    stack<string>st;
    string prefix="*-A/BC-/AKL";
    for(int i=prefix.size()-1;i>=0;i--)
    {
        if(isoperand(prefix[i]))
        {
            st.push(string(1,prefix[i]));
        }
        else
        {
            string a=st.top();
            st.pop();
            string b=st.top();
            st.pop();
            string s='('+a+prefix[i]+b+')';
            st.push(s);
        }
    }
    cout<<st.top();
    // ((A-(B/C))*((A/K)-L))
}