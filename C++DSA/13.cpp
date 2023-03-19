//////////letter count problem
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,char>v1,pair<int,char>v2)
{
    if(v1.first!=v2.first) return v1.first>v2.first;
    return v1.second<v2.second;
}
int main()
{
    string s;
    cin>>s;
    map<char,int>m;
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }
    
    vector<pair<int,char>>v(m.size());
    int i=0;
    for(auto it:m)
    {
        v[i].first=it.second;
        v[i].second=it.first;
        i++;
    }
    
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].second;

}