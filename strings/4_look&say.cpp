//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        string ans="1";
        if(n==1) return ans;
        for(int i=2;i<=n;i++)
        {
            string temp="";
            int count=1;
            for(int j=0;ans[j]!='\0';)
            {
                while(ans[j]==ans[j+1])
                {
                    count++;
                    j++;
                }
                temp+=to_string(count)+ans[j++];
                count=1;
            }
            ans=temp;
            
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends