//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool bipbfs(vector<int>adj[],int curr,vector<int>&color,int currcolor)
{
    queue<int>q;
    q.push(curr);
    color[curr]=currcolor;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(color[v]==color[u])return false;
            else if(color[v]==-1)//never visited and not colored yet
            {
                color[v]=1-color[u];
                q.push(v);
            }
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
	            if(bipbfs(adj,i,color,1)==false )return false;
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