//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    // long long int dp[1001][1001];
    long long int  countPS(string str)
    {
       //Your code here
       long long int dp[str.length()][str.length()];
        for(long long int diagonal=0;diagonal<str.length();diagonal++)
        {
            for(long long int i=0,j=diagonal;j<str.length();i++,j++)
            {
                if(diagonal==0) dp[i][j]=1;
                else if(diagonal==1)
                {
                    dp[i][j]=(str[i]==str[j])?3:2;
                }
                else{
                if(str[i]==str[j]) dp[i][j]=((dp[i][j-1]%1000000007)+(dp[i+1][j]%1000000007)+1)%1000000007;
                else dp[i][j]=((dp[i+1][j]%1000000007)+(dp[i][j-1]%1000000007)-(dp[i+1][j-1]%1000000007)+1000000007)%1000000007;
                }
            }
        }
        return (dp[0][str.length()-1])%1000000007;
        
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends