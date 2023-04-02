//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        set<char>st;
        for(int i=0;i<str.length();i++)
        {
            st.insert(str[i]);
        }
        int n=st.size();
        map<char,int>mp;
        int count=0;
        int start=0;
        int ans=str.length();
        int end;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
            // cout<<str[i]<<' '<<mp[str[i]]<<endl;
            if(mp[str[i]]==1){
                count++;
            }
            if(count==n){
                while(mp[str[start]] >1 ){
                    // cout<<str[start]<<' '<<mp[str[start]]<<' '<<"deleted"<<endl;
                    mp[str[start]]--;
                    start++;
                    ans=min(ans,i-start+1);
                    // cout<<i<<' '<<str[start]<<' '<<start<<' '<<mp[str[start]]<<' '<<count<<' '<<n<<endl;
                }
            }
            end=i;
        }
        while(mp[str[end]]>1){
            cout<<str[end]<<' '<<mp[str[end]]<<endl;
            mp[str[end]]--;
            end--;
            ans=min(ans,end-start+1);
            cout<<str[end]<<' '<<mp[str[end]]<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends