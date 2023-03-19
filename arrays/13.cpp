// comparator function in c++
#include<bits/stdc++.h>
using namespace std;
bool  compare(pair<int,int>p1 , pair<int,int>p2)
{
    cout<<"p1.first and p2.first are: ";
    cout<<p1.first<<" "<<p2.first<<endl;
    if(p1.first < p2.first) return true;
    else return false;
}
int main()
{
    vector<pair<int,int>>vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        pair<int,int>p;
        cin>>p.first>>p.second;
        vec.push_back(p);
    }
    for(int i=0;i<n;i++)
    {
        pair<int,int>p=vec[i];
        cout<<p.first<<" "<<p.second<<endl;
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<n;i++)
    {
        pair<int,int>p=vec[i];
        cout<<p.first<<" "<<p.second<<endl;
    }
}