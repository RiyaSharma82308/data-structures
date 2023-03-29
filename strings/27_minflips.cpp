//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n=S.length();
    string s1="";
    string s2="";
    char a='0';
    char b='1';
    for(int i=0;i<n;i++)
    {
        s1+=a;
        s2+=b;
        char temp=a;
        a=b;
        b=temp;
    }
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=S[i]) count1++;
        if(s2[i]!=S[i]) count2++;
    }
    if(count1>count2) return count2;
    return count1;
}