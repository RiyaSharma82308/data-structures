#include<bits/stdc++.h>
using namespace std;
// bool comp()
int main(){
    int n=2;
    int m=5;
    int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 };
    vector<pair<int,int>>v[n+1];
    for(int i=0;i<m;i++)
    {
        v[arr[i][2]].push_back(make_pair(arr[i][1],arr[i][0]));
    }
    for(int i=0;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    // vector<int>vec(n+1,0);
    int count=0;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        count++;
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j].second>=v[i][x].first)
            {
                // cout<<count<<endl;
                count++;
                x=j;
            }
        }
    }
    cout << "Maximum Stopped Trains = "
         << count;
}
