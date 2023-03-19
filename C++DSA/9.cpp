# include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v={"riya@gmail.com","sduhei@gmail.com","sharma@yahoo.com","riya@yml.com","sharma@redifmail.com"};
    vector<pair<string,int>> ans;
    map<string,int> m;
    for(int i=0;i<v.size();i++)
    {
        auto index=v[i].find('@');
        m[v[i].substr(index+1)]++;
    }
    for(auto it: m)
    {
        ans.push_back({it.first,it.second});
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
