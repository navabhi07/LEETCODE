//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],int u,vector<bool>&vis,stack<int>&st)
	{
	    vis[u]=true;
	    
	    
	    for(auto &v:adj[u])
	    {
	        if(!vis[v])dfs(adj,v,vis,st);
	    }
	    // bbad mein stack mein dalo phle jo unvisiited hau usko call kr lo 
	    st.push(u);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>vis(v,false);
	    stack<int>st;
	    for(int i=0;i<v;i++)
	    {
	        if(!vis[i])dfs(adj,i,vis,st);
	    }
	    vector<int>res;
	    while(!st.empty())
	    {
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends