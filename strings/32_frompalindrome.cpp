#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int lcs(string str){
        int dp[str.length()+1][str.length()+1];
        for(int i=0;i<str.length()+1;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        string str2=str;
        reverse(str2.begin(),str2.end());
        for(int i=1;i<str.length()+1;i++){
            for(int j=1;j<=str.length();j++){
                if(str[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[str.length()][str.length()];
    }
    int countMin(string str){
    
        int n=str.length();

        return n-lcs(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends