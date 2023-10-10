//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool iscycle(vector<int>adj[],vector<int>&vis,int strt,int pare)
  {
      vis[strt]=1;
      for(auto it:adj[strt])
      {
          
          if(it==pare)continue;
          if(vis[it]==1)return true;
          if(iscycle(adj,vis,it,strt)==1)return true;
      }
      return false;
  }
  
  
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&iscycle(adj,vis,i,-1))return true;
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends