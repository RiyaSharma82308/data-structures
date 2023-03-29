#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int func(vector<vector<char> > &mat, string target ,int i,int j,int idx, int size, int row, int col)
    {
        if(i>=0 && j>=0 && i<row && j<col && target[idx]==mat[i][j])
        {
            if(idx ==size-1){
                return 1;
            }
            char temp= mat[i][j];
            mat[i][j]='0';
            // idx+=1;
            int a1= func(mat, target, i+1, j, idx+1, size,row,col);
            int a2= func(mat, target, i-1, j, idx+1, size,row,col);
            int a3= func(mat, target, i, j+1, idx+1, size,row,col);
            int a4= func(mat, target, i, j-1, idx+1, size,row,col);
            mat[i][j]=temp;
            return a1+a2+a3+a4;
        }
        else return 0;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        int idx=0;
        int size=target.length();
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                ans+=func(mat,target,i,j,idx,size, row, col);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends