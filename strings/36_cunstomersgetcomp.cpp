#include<bits/stdc++.h>
#include<cstring>
using namespace std;
 
#define MAX_CHAR 26
int  runCustomerSimulation(int n, string str)
{
    vector<int>vec(MAX_CHAR,0);
    int count=0;
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
        vec[str[i]-'A']++;
        if(vec[str[i]-'A']==1) {
            count++;
            if(count>n) {
                ans++;
            }
        }
        if(vec[str[i]-'A']==2) {
            count--;
        }

    }
    return ans;
}
// Driver program
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}