#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        char a=S[0];
        string ans="";
        ans.push_back(a);
        for(int i=1;i<S.length();i++)
        {
            if(S[i]!=S[i-1]) ans.push_back(S[i]);
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




