#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    st.push(10000);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    while(st.top()<100)
    {
        st.pop();
    }
    cout<<st.top();
}