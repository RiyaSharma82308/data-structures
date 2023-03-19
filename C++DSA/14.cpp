#include<bits/stdc++.h>
bool possible(int n, int m, vector<int> &time,long long int mid)
{
    long long int tc=0;
    int dc=1;
    for(int i=0;i<m;i++)
    {
        if(tc+time[i]<=mid)
        {
            tc+=time[i];
        }
        else
        {
            dc++;
            if(dc>n || time[i]>mid)
            {
                return false;
            }
            tc=time[i];
        }
    }
    return true;
    
}
int find(int n, int m, vector<int> &time,long long int sum)
{
    long long int s=0;
    long long int e=sum;
    long long int ans=-1;
    long long int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(possible(n,m,time,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long int sum=accumulate(time.begin(),time.end(),0);
    return find(n,m,time,sum);
    
}