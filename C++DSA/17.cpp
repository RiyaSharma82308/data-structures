#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m;
	vector<long long int>vec(n);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		int p=0;
		for(int i=0;i<n;i++)
		{
			int rem=(vec[i]+x)%m;
			if(rem>p)
			{
				p=rem;
			}
		}
		cout<<p<<endl;
	}
}