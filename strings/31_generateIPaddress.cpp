//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  bool check(string s){
      if(s.length()>3 || s.length()<=0) return false;
      if(s[0]=='0' && s.length()>1) return false;
      if(stoi(s) >255 || stoi(s)<0) return false;
      else return true;
      
  }
  string func(string s , int n, int i, int j, int k)
  {
      string s1= s.substr(0,i+1);
      string s2= s.substr(i+1,j-i);
      string s3= s.substr(j+1,k-j);
      string s4= s.substr(k+1,n-1-k);
      if(check(s1) && check(s2) && check(s3) && check(s4)){
          return s1+"."+s2+"."+s3+"."+s4;
      }
      return "";
  }
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>vec;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i+1;j<s.length();j++)
            {
                for(int k=j+1;k<s.length();k++)
                {
                    string a= func(s,s.length(),i,j,k);
                    if(a.length()>1){
                        vec.push_back(a);
                    }
                }
            }
        }
        if(vec.empty()) vec.push_back("-1");
        return vec;

        
    }

};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends