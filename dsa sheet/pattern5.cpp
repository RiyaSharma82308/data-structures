// 1 
// 8 2 
// 14 9 3 
// 19 15 10 4 
// 23 20 16 11 5 
// 26 24 21 17 12 6 
// 28 27 25 22 18 13 7 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    int k=1;
    vector<vector<int>>vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        int num=k;
        int p=0;
        for(int j=i;j<n;j++)
        {
            vec[j][i]=num;
            num=num+n-p;
            p++;
        }
        k++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<vec[i][j]<<' ';
        }
        cout<<endl;
    }
}