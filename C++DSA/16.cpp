#include<bits/stdc++.h>
using namespace std;
void func(string str,vector<string>&vec,int index)
{
    // cout<<"hi"<<endl;
    if(index >= str.size())
    {
        vec.push_back(str);
        return;
    }
    for(int i=index;i<str.size();i++)
    {
        swap(str[i],str[index]);
        func(str,vec,++index);
        swap(str[i],str[index]);
    }
}
int main()
{
    string str="abcde";
    vector<string>vec;
    func(str,vec,0);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
}