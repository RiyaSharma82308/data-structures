// comparator function
#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    cout<<"a & b are: "<<a<<" "<<b<<endl;
    if(a<0 && b>0)
    {
        return (a<0 && b>0);
    }
    else if(a==0 && b>0) return (a==0 && b>0);
    else if(a<0 && b==0) return true;
    else return false;
}
int main()
{
    int arr[5]={20,-1,5,-3,0};
    sort(arr,arr+5,comp);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}