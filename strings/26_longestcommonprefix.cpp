//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string func(string a, string b)
    {
        string temp="";
        for(int i=0,j=0;i<a.length(),j<b.length();i++,j++)
        {
            if(a[i]==b[j]){
                temp+=a[i];
            }
            else{
                return temp;
            }
        }
    }
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string temp=arr[0];
        for(int i=1;i<N;i++){
            temp=func(arr[i],temp);
        }
        if(temp=="") return "-1";
        return temp;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends