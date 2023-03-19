#  include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_map<string ,int>m;
    while(n--)
    {
        string s;
        cin>>s;
        if(m.find(s)==m.end())
        {
            m[s];
            cout<<"OK"<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                s.push_back(i+'0');
                cout<<s<<endl;
                if(m.find(s)==m.end())
                {
                    cout<<s<<endl;
                    m[s];
                    break;
                }
                else{
                    s.pop_back();
                }
            }
        }

    }
}