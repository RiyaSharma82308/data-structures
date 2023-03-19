# include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="zerootwneozerothre";
    int n=s.size();
    map<char,int> m;
    for(int i=0;i<n;i++)
    {
        m[s[i]]++;
    }
    string ans;
    while(m['z'] && m['e'] && m['r'] && m['o'])
    {
        m['z']--;m['e']--;m['r']--;m['o']--;
        ans.push_back('0'+0);
    }
    while(m['o'] && m['e'] && m['n'] )
    {
        m['o']--;m['n']--;m['e']--;
        ans.push_back(1+'0');
    }
    while(m['t'] && m['w'] && m['o'])
    {
        m['t']--;m['w']--;m['o']--;
        ans.push_back(2+'0');
    }
    while(m['t'] && m['h'] && m['r'] && m['e']==2 )
    {
        m['t']--;m['h']--;m['r']--;m['e']--;m['e']--;
        ans.push_back('0'+3);
    }
    while(m['f'] && m['u'] && m['r'] && m['o'])
    {
        m['f']--;m['o']--;m['u']--;m['r']--;
        ans.push_back('0'+4);
    }
    while(m['f'] && m['e'] && m['v'] && m['i'])
    {
        m['f']--;m['i']--;m['v']--;m['e']--;
        ans.push_back('0'+5);
    }
    while(m['s'] && m['i'] && m['x'] )
    {
        m['s']--;m['i']--;m['x']--;
        ans.push_back('0'+6);
    }
    while(m['s'] && m['e']==2 && m['v'] && m['n'])
    {
        m['s']--;m['e']--;m['v']--;m['e']--;m['n']--;
        ans.push_back('0'+7);
    }
    while(m['e'] && m['i'] && m['g'] && m['h'] && m['t'])
    {
        m['e']--;m['i']--;m['g']--;m['h']--;m['t']--;
        ans.push_back('0'+8);
    }
    while(m['n']==2&& m['e'] && m['i'])
    {
        m['n']--;m['i']--;m['e']--;m['n']--;
        ans.push_back('0'+9);
    }
    cout<<ans<<endl;
}