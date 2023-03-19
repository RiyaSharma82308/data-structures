#include <bits/stdc++.h>
using namespace std;
pair<int,int> func(int x,int y,int n,int r,int a,int b)
{
    //cout<<"insdude"<<endl;
    pair<int,int>p;
    if((x*a+y*b)<=r && a+b==n)
    {
        p.first=a;
        p.second=b;
        return p;
    }
    if((a>n || b<0))
    {
        p.first=-1;
        p.second=-1;
        return p;
    }
    cout<<a<<' '<<b<<endl;
    return func(x,y,n,r,++a,--b);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
        
	    int x,y,n,r;
	    cin>>x>>y>>n>>r;
	    int a=0; int b=n;
	    pair<int,int>p;
        p=func(x,y,n,r,a,b);
        cout<<"hi"<<endl;;
	    if(p.first==-1 && p.second==-1)
	    {
	        cout<<-1<<endl;
	    }
	    else
	    cout<<p.first<<' '<<p.second<<endl;
	}
	return 0;
}
