//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        vector<vector<int>>dp(s.length(),vector<int>(s.length()));
        string ans=" ";
        int length=0;
        int new_length=0;
        for(int g=0; g<s.length(); g++)
        {
            for(int i=0,j=g; j<s.length(); i++,j++)
            {
                // cout<<"hi "<<g<<endl;
                if(g==0)dp[i][j]=1;
                else if(g==1)
                {
                    // cout<<"here 1"<<endl;
                    if(s[i]==s[j]) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else
                {

                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        // cout<<"here2"<<endl;
                        dp[i][j]=1;
                    }
                    else{
                        // cout<<"here3"<<endl;
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j])
                {
                    new_length=g+1;
                }
                if(dp[i][j] && new_length>length )
                {
                    string temp=s.substr(i,j-i+1);
                    ans=temp;
                    length=new_length;
                    // cout<<i<<' '<<j<<' '<<ans<<endl;
                }
            }
            // cout<<g<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends