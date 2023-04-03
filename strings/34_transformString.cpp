//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        map<char,int>mp1;
        for(int i=0;i<A.length();i++)
        {
            mp1[A[i]]++;
        }
        for(int i=0;i<B.length();i++)
        {
            mp1[B[i]]--;
        }
        for(auto itr:mp1)
        {
            if(itr.second !=0) return -1;
        }
        int ans=0;
        for(int i=A.length()-1, j=B.length()-1; i>=0 && j>=0 ;)
        {
            if(A[i]==B[j]) 
            {
                i--; j--;
            }
            else{
                ans++;
                i--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends