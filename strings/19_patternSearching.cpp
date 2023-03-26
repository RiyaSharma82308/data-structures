//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int>vec;
            for(int i=0;i<=txt.length()-pat.length();i++)
            {
                string temp=txt.substr(i,pat.length());
                if(temp!=pat) continue;
                else{
                    vec.push_back(i+1);
                }
            }
            if(vec.empty()) vec.push_back(-1);
            return vec;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends