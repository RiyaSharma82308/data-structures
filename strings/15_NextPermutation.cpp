//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        vector<int>ans;
        int index=-1;
        for(int i=N-1;i>0;i--)
        {
            if(arr[i]>arr[i-1]){
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            for(int i=N-1;i>=0;i--){
                ans.push_back(arr[i]);
            }
        }
        else
        {
            int prev=index;
            for(int i=index+1;i<N;i++)
            {
                if(arr[i]>arr[index-1] && arr[i]<=arr[prev]){
                    prev=i;
                }
                // cout<<index<<' '<<prev<<endl;
            }
            // cout<<index<<endl;
            swap(arr[index-1],arr[prev]);
            reverse(arr.begin()+index,arr.end());
            for(int i=0;i<N;i++){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends