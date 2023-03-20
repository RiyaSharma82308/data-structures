#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    map<char,int>mp;
    for(int i=0;i<str.length();i++)
    {
        mp[str[i]]++;
    }
    for(auto itr:mp)
    {
        if(itr.second >1)
        {
            cout<<itr.first<<' '<<itr.second<<endl;
        }
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}