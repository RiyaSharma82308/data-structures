#include<bits/stdc++.h>
using namespace std;
string reverseWord(string str);
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}
string reverseWord(string str){
  reverse(str.begin(),str.end());
  return str;
}

