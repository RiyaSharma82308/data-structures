//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count=0;
        stack<char>st;
        for(int i=0;i<str.length();i++)
        {
            if( (!st.empty()) && (st.top()!= str[i]) )
            {
                st.pop();
                if(st.empty()) count++;
            }
            else st.push(str[i]) ;
        }
        if (st.empty()) return count;
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends