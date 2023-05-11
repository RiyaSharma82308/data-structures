#include<bits/stdc++.h>
using namespace std;
void func(vector<vector<int>>&vec, int n, int count, int i, int j, int ans){
    if(ans==1) return;
    if( i<0 || i>=n || j<0 || j>=n || vec[i][j]!=-1){
        // cout<<"ends"<<endl;
        // ans=1;
        return;
    }
    if(count==n*n) {
        vec[i][j]=count;
        // cout<<"printing "<<count<<endl;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                cout<<vec[row][col]<<' ';
            }
            cout<<endl;
        }
        vec[i][j]=-1;
        ans=1;
        return;
    }

    cout<<count<<endl;
    vec[i][j]=count;
    // count++;
    func(vec,n,count+1,i-2,j+1,ans);
    func(vec,n,count+1,i-1,j+2,ans);
    func(vec,n,count+1,i+1,j+2,ans);
    //<<"hrere"<<endl;
    func(vec,n,count+1,i+2,j+1,ans);
    func(vec,n,count+1,i+2,j-1,ans);
    func(vec,n,count+1,i+1,j-2,ans);
    func(vec,n,count+1,i-1,j-2,ans);
    func(vec,n,count+1,i-2,j-1,ans);
    // count--;
    vec[i][j]=-1;
    return;
}
int main(){
    int count=1;
    int n=8;
    vector<vector<int>>vec(n,vector<int>(n,-1));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<< vec[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    func(vec,n,count,0,0,0);

}