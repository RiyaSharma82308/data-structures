//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[502][2002];
    int func(int i,int rem,vector<int>&arr,int k)
    {
        if(i==arr.size()) return 0;
        if(dp[i][rem]!=-1) return dp[i][rem];
        int ans;
        if(arr[i] > rem){
            ans=(rem+1)*(rem+1) + func(i+1,k-arr[i]-1,arr,k);
        }
        else{
            int a1=(rem+1)*(rem+1) + func(i+1,k-arr[i]-1,arr,k);
            int a2=func(i+1,rem-arr[i]-1,arr,k);
            ans=min(a1,a2);
        }
        dp[i][rem]=ans;
        return dp[i][rem];
    }
    int solveWordWrap(vector<int>arr, int k) 
    { 
        // Code here
        memset(dp,-1,sizeof(dp));
        return func(0,k,arr,k);
       
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends