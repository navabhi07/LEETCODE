//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        // Code here
        vector<int>res(v,1e8);
        res[s]=0;
        
        for(int i=1;i<=v-1;i++)
        {
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                if(res[u]!=1e8&&res[u]+w<res[v])
                {
                    res[v]=res[u]+w;
                }
            }
        }
        
        // to detect -ve cycle ,ek baar extra relax kr de rha hun;
         for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                if(res[u]!=1e8&&res[u]+w<res[v])
                {
                    //agr kch change hoga toh isme aayega so
                    
                    return{-1};
                    
                }
            }
            
            return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends