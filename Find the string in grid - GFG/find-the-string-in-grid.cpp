//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool f(string word,vector<int>&x,vector<int>&y,int i,int j,vector<vector<char>>&grid)
{
    
        int n=grid.size();
        int m=grid[0].size();
         int k=0;
        for(int dir=0;dir<8;dir++)
        {
             int i1=i,j1=j,k=0;
           
           
          
           while(i1<n&&i1>=0&&j1<m&&j1>=0&&k<word.size())
           {
               if(word[k]==grid[i1][j1])
               {
                   k++;
                   i1+=x[dir];
                   j1+=y[dir];
               }
               else
               {
                   break;
               }
           }
           
           if(k==word.size())return true;
        }
        
         return false;
    
   
    
    
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    
	    vector<int>x={-1,-1,0,1,1,1,0,-1};
	    vector<int>y={0,1,1,1,0,-1,-1,-1};
	    vector<vector<int>>ans;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(f(word,x,y,i,j,grid))
	            {
	                vector<int>v;
	                v.push_back(i);
	                v.push_back(j);
	                ans.push_back(v);
	            }
	            
	        }
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