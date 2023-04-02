//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>ans;
        for(int i=0;i<string_list.size();i++){
            if(string_list[i].compare("-1")==0) continue;
            string temp=string_list[i];
            sort(temp.begin(),temp.end());
            vector<string>vec;
            vec.push_back(string_list[i]);
            for(int j=i+1;j<string_list.size();j++)
            {
                string s=string_list[j];
                sort(s.begin(),s.end());
                int a=s.compare(temp);
                if(a == 0){
                    vec.push_back(string_list[j]);
                    string_list[j]="-1";
                }
            }
            ans.push_back(vec);
        }
        sort(ans.begin(),ans.end());
        return ans;
        // return sort(ans.begin(),ans.end());
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends