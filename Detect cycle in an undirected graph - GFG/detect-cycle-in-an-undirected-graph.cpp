//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool iscyclebfs(vector<int>adj[],vector<int>&vis,int strt)
  {
      queue<pair<int,int>>q;
      q.push({strt,-1});
      vis[strt]=1;
      while(!q.empty())
      {
          pair<int,int>p=q.front();
          q.pop();
          int source=p.first;
          int parent=p.second;
          
          for(auto it:adj[source])
          {
              if(!vis[it])
              {
                  vis[it]=1;
                  q.push({it,source});
              }
              else if(it!=parent)return true;
          }
      }
      return false;
  }
  
  
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&iscyclebfs(adj,vis,i))return true;
            
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