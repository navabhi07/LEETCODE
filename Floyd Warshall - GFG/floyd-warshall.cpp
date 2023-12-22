//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    // Code here
	    // sabse pehle toh yahan jo diya hua hai matrix usme mein -1 diya gua hai
	    // jiske /w edge nhi hai lekin jo humlog pdhein hain usme infinity liyen hai
	    //ya koi bds number hai so pehle hum usko change kr lete hain tb asani hogi bnanae mein question
	    int n=mat.size();
	    
	    for(int i=0;i<n;i++ )
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(mat[i][j]==-1)mat[i][j]=1e9;
	        }
	    }
	    
	    
	    for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
	            }
	        }
	    }
	    // yahn pe jo value pe 1e9 dalein hain usko change kr ete hain -1 se so anser shi aayega 
	    
	    for(int i=0;i<n;i++ )
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(mat[i][j]==1e9)mat[i][j]=-1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends