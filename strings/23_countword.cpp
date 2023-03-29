//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool func(vector<vector<char>> grid, string word, int i, int j, int row, int col, int size)
    {
        vector<int>dir_row{-1,-1,-1,0,1,1,1,0};
        vector<int>dir_col{-1,0,1,1,1,0,-1,-1};
        for(int dir=0;dir<8;dir++)
        {
            // cout<<"hi"<<endl;
            int rd=i+dir_row[dir];
            int cd=j+dir_col[dir];
            int k;
            for(k=1;k<size;k++){
                // cout<<k<<' '<<i <<' '<<j<<endl;
                if(rd<0 || cd<0 || rd>=row || cd>=col )
                {
                    break;
                }
                if(word[k]!=grid[rd][cd]){
                    break;
                }
                rd+=dir_row[dir];
                cd+=dir_col[dir];
            }
            if(k==size) return 1;
        }
        return 0;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>ans;
	    int row=grid.size();
	    int col=grid[0].size();
	    int idx=0;
	    set<vector<int>>s;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            vector<int>vec;
	            int a=0;
	           // cout<<j<<endl;
	            if(grid[i][j]==word[0]){
    	           // a=func(grid,word,i,j,row,col,word.length());
    	            if(func(grid,word,i,j,row,col,word.length()))
    	            { 
    	                vec.push_back(i);
        	            vec.push_back(j);
        	            ans.push_back(vec);
    	            }
	            }
	        }
	    }
	    if(ans.empty()){
	        vector<int>vec;
	        vec.push_back(-1);
	        ans.push_back(vec);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends