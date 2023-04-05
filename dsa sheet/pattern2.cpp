// * * * * *  * * * * *
// * * * *      * * * *
// * * *          * * *
// * *              * *
// *                  *
// *                  *
// * *              * *
// * * *          * * *
// * * * *      * * * *
// * * * * *  * * * * *

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>=5-i && j<= 5+i-1) cout<<' ';
            else cout<<'*';
        }
        cout<<endl;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>=1+i && j<n-i-1) cout<<' ';
            else cout<<'*';
        }
        cout<<endl;
    }
}