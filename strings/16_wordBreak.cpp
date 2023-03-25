#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<string,int>dp;
    int func(string A, vector<string>&B)
    {
        int length=A.length();
        if(length==0) return 1;
        if(dp[A]!=0) return dp[A];
        for(int i=1;i<=A.length();i++)
        {
            string temp=A.substr(0,i);
            int flag=0;
            for(int j=0;j<B.size();j++)
            {
                if(temp.compare(B[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1 && func(A.substr(i,length-i),B)==1){
                return dp[temp]=1;
            }
            
        }
        return dp[A]=-1;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int a=func(A,B);
        if(a==1) return 1;
        return 0;;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends