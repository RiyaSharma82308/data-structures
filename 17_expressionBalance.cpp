//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.length()%2 == 1) return -1;
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty() && s[i]=='}')
        {
            if(st.top()=='{') st.pop();
            else st.push(s[i]);
        }
        else{
            st.push(s[i]);
        }
    }
    int size=st.size();
    int count=0;
    while( !st.empty() && st.top()=='{')
    {
        count++;
        st.pop();
    }
    return ((size/2) + (count%2));
}