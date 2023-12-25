//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:

	vector<int> parent;
    vector<int> rank;

    int find (int x) {
    if (x == parent[x]) 
        return x;

    return parent[x] = find(parent[x]);
   }

   void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
  }


	
	
	int kruskal(vector<vector<int>>&vec)
	{
	    int sum=0;
	    for(auto temp:vec)
	    {
	        int u=temp[0];
	        int v=temp[1];
	        int wt=temp[2];
	        
	        int pu=find(u);
	        int pv=find(v);
	        
	        if(pu!=pv)
	        {
	             Union(u,v);
	             sum+=wt;
	        }
	    }
	    
	    return sum;
	}
	
	
	
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        parent .resize(v);
        rank.resize(v,0);
        for(int i=0;i<v;i++)parent[i]=i;
        vector<vector<int>>vec;
        
        for(int u=0;u<v;u++)
        {
            for(auto temp:adj[u])
            {
                int v=temp[0];
                int w=temp[1];
                
                vec.push_back({u,v,w});
            }
        }
        
        auto cmp=[&](vector<int>&v1,vector<int>&v2)
        {
           return v1[2]<v2[2]; 
        };
        
        sort (vec.begin(),vec.end(),cmp);
        
        return kruskal(vec);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends