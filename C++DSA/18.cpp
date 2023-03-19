#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&vec,int n, int a)
{
    if(a>n)
    {
        return;
    }
    vector<int>v(a+1);
    v[0]=1;
    for(int i=1;i<a+1;i++)
    {
        if(i==a)
        {
            v[i]=1;
        }
        else
        {
            v[i]=vec[i-1]+vec[i];
        }
    }
    for(int i=0;i<a+1;i++)
    {
        vec[i]=v[i];
    }
    func(vec,n,a+1);
}
int main()
{
    vector<int>vec(2);
    vec[0]=1;
    func(vec,1,1);
    for(int i=0;i<2;i++)
    {
        cout<<vec[i]<<endl;
    }
}