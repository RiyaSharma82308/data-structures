//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string func(string S)
    {
        // cout<<S<<endl;
        if(S[0]=='\0') return S;
        if(S[0]==S[1])
        {
            return func(S.substr(1));
        }
        else{
            return S[0]+func(S.substr(1));
        }
    }
    
    string removeConsecutiveCharacter(string S)
    {
        int index=0;
        S=func(S);
        return S;
    }
};

//{ Driver Code Starts.
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




// } Driver Code Ends