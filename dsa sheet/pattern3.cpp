// *                  *
// * *              * *
// * * *          * * *
// * * * *      * * * *
// * * * * *  * * * * *
// * * * * *  * * * * *
// * * * *      * * * *
// * * *          * * *
// * *              * *
// *                  *

#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j>i && j<10-1-i) cout<<' ';
            else cout<<'*';
        }
        cout<<endl;
    }
    for(int i=4;i>=0;i--)
    {
        for(int j=0;j<10;j++)
        {
            if(j>i && j<10-1-i) cout<<' ';
            else cout<<'*';
        }
        cout<<endl;
    }
}