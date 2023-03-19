//////same question in next file with less time complexity
# include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int arr[26]={0};
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            char c=s[i];
            arr[c-'a']++;
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            char c=s[i];
            arr[c-'A']++;
        }  
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i]%2!=0 && arr[i]!=0)
        {
            count++;
        }
    }
    if(count>1)
    {
        cout<<"no";
    }
    else{
        cout<<"yes";
    }
}