# include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[3]={1,2,3};
    int arr2[3]={4,5,6};
    pair<int,int>p[3];
    // p[0]={1,4};
    // p[1]={2,5};
    // p[2]={3,6};
    for(int i=0;i<3;i++)
    {
        p[i]={arr1[i],arr2[i]};
    }
    //cout<<p[0].first;
    for(int i=0;i<3;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
}