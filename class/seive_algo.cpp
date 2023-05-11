#include<bits/stdc++.h>
using namespace std;
vector<int> seive(int n){
    vector<int>vec(n+1,1);
    vec[0]=0;
    vec[1]=0;
    for(int i=2;i<=n;i++){
        if(vec[i]==1){
            for(int j=i*i;j<=n;j+=i){
                if(j%i==0) vec[j]=0;
            }
        }
    }
    vector<int>ans;
    for(int i=2;i<=n;i++){
        if(vec[i]==1) {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    int n=12;
    vector<int>vec;
    int l=110;
    int r=130;
    vector<int>verify=seive(r);
    for(int i=0;i<verify.size();i++){
        cout<<verify[i]<<' ';
    }
    cout<<endl;
    vec=seive(sqrt(r));
    vector<pair<int,bool>>temp;
    for(int i=l;i<=r;i++){
        temp.push_back(make_pair(i,true));
    }
    for(int i=0;i<vec.size();i++){
            for(int j=0;j<temp.size();j++){
                if((temp[j].first)%vec[i]==0){
                    temp[j].second=false;
                }
            }
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i].second==true) cout<<temp[i].first<<' '; 
    }
    

}