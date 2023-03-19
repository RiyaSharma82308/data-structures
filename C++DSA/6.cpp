/////// cehck if a string can be made into a palindrome or not in a particular range
# include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N][26];
int main()
{
    int q,n;
    cin>>q>>n;
    string s;
    cin>>s;
    
    for(int i=0;i<n;i++)
    {
        arr[i+1][s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[j][i]+=arr[j-1][i];
        }
    }
   // cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int odd=0;
        for(int i=0;i<26;i++)
        {
            int chrcount=arr[r][i]-arr[l-1][i];
            if(chrcount%2!=0)
            {
                odd++;
            }
        }
        if(odd>1)
        {
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }

    }

}