//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool bipdfs(vector<int>adj[],int curr,vector<int>&color,int currcolor)
{
    color[curr]=currcolor;
    for(auto v:adj[curr])
    {
        if(color[v]==color[curr])return false;
        
        if(color[v]==-1)
        { // this node is never visted till  now
             int colorofv=1-currcolor;
             if(bipdfs(adj,v,color,colorofv)==false)return false;
        }
    }
    
    return true;
}
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int>color(v,-1);
	    // red=1
	    //green=0;
	    
	    for(int i=0;i<v;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(bipdfs(adj,i,color,1)==false )return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends