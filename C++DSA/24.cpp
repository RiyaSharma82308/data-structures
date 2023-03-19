#include<bits/stdc++.h>
using namespace std;
int findpivot(vector<int>&vec,int s,int e)
{
    int mid=(s+e)/2;
    if(s>=e)
    {
        return mid;
    }
    if(vec[mid]>=vec[0])
    {
        int p=findpivot(vec,mid+1,e);
        return p;
    }
    else if(vec[mid]<vec[0])
    {
        int p= findpivot(vec,s,mid);
        return p;
    }
}
int main()
{
    vector<int>vec={4,5,1,2,3};
    int a=findpivot(vec,0,4);
    cout<<a;
}