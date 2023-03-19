# include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e3+10;
int pff[N][M];
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            pff[i][j]=arr[i][j]+pff[i-1][j]+pff[i][j-1]-pff[i-1][j-1];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pff[c][d]-pff[a-1][d]-pff[c][b-1]+pff[a-1][b-1]<<endl;
    }
}