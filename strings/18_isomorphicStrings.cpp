//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.length()!=str2.length()) return false;
        vector<char>vec(26,'1');
        for(int i=0;i<str1.length();i++)
        {
            if(vec[str1[i]-'a']!='1' && vec[str1[i]-'a']!=str2[i])
            {
                // cout<<"in if statement "<<str1[i]-'a'<<' '<<vec[str1[i]-'a']<<' '<<str2[i]<<endl;
                return false;
            }
            else if(vec[str1[i]-'a']=='1')
            {
                // cout<<"here"<<endl;
                vec[str1[i]-'a']=str2[i];
            }
        }
        // vector<int>check(26,0)
        map<char,int>mp;
        for(int i=0;i<26;i++)
        {
            mp[vec[i]]++;
        }
        for(auto itr:mp)
        {
            if(itr.first != '1' && itr.second>1 ) return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends