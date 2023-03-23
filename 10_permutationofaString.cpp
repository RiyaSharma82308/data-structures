//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:

        void func(string &s,int l,int r,set<string>&vec)
        {
            if(l==r) 
            {
                vec.insert(s);
                return;
            }
            else{
                for(int i=l;i<r;i++)
                {
                    swap(s[l],s[i]);
                    func(s,l+1,r,vec);
                    swap(s[l],s[i]);
                }
            }
        }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>ans;
		    int l=0;
		    int r=S.length();
		    func(S,l,r,ans);
		  //  unique(ans.begin(),ans.end());
		    vector<string>vec(ans.begin(),ans.end());
		    return vec;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends