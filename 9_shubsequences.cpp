#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input,string output,int i,vector<string>&vec)
{
    if(i==input.length())
    {
        // cout<<output<<endl;
        vec.push_back(output);
        return;
    }
    // cout<<i<<endl;
    printSubsequence(input,output,i+1,vec);
    printSubsequence(input,output+input[i],i+1,vec);
}
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = " ";
    string input = "abcd";
    int i=0;
    vector<string>vec;
    printSubsequence(input, output,i,vec);
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
    return 0;
}