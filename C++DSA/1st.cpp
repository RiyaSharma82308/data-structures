////// hashing
/////// all the computations are done before outside the loop and stores in array
# include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long int arr1[N];
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
      arr1[arr[i]]++;
   }
   int x;
   cin>>x;
   cout<<arr1[x];


}