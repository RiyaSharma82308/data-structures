//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    vector<int>vec(26,-2);
    for(int i=0;i<s.length();i++)
    {
        if(vec[s[i]-'a'] ==-2) {
            vec[s[i]-'a']=-1;
        }
        else if(vec[s[i]-'a'] ==-1) vec[s[i]-'a']=i;
    }
    int min=s.length();
    for(int i=0;i<26;i++)
    {
        if(vec[i]>0 && vec[i]<min){
            min=vec[i];
            // cout<<min<<endl;
        }
    }
    string ans="";
    if(min!=s.length())ans+=s[min];
    if(ans!="")return ans;
    return "-1";
}