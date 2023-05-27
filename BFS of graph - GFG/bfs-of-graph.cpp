//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        //1.make a visited array and initialize with 0 if starting node is 1 then size of vis array is
        //int vis[v+1];
        int vis[v]={0};
        // make starting index visited by 1
        vis[0]=1;
        //2.take a queue in bfs
        queue<int>q;
         // push the initial starting node
        q.push(0);
         // iterate till the queue is empty 
        while(!q.empty())
        {
            // get the topmost element in the queue 
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            // traverse for all its neighbours 
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends