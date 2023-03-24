// Check if the given string is shuffled substring of another string
#include<bits/stdc++.h>
using namespace std;
bool isShuffledSubstring(string str1,string str2)
{
    map<char,int>mp1;
    for(int i=0;i<str1.length();i++)
    {
        mp1[str1[i]]++;
    }
    map<char,int>mp2;
    for(int i=0;i<str2.length();i++)
    {
        mp2[str2[i]]++;
    }
    for(auto itr:mp1)
    {
        for(auto i:mp2)
        {
            if(itr.first==i.first)
            {
                if(itr.second > i.second) return false;
            }
        }
    }
    return true;
}
int main()
{
    string str1 = "onetwofou";
    string str2 = "hellofourtwooneworld";

    bool a = isShuffledSubstring(str1, str2);
    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}