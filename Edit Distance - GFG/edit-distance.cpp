//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    int f(string s,string t,int ind1,int ind2,vector<vector<int>>&dp)
    {
        if(ind1<0)return ind2+1;
        if(ind2<0)return ind1+1;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2]) return dp[ind1][ind2]= f(s,t,ind1-1,ind2-1,dp);
        else
    {
        return dp[ind1][ind2]=1+min({f(s,t,ind1-1,ind2,dp),f(s,t,ind1,ind2-1,dp),f(s,t,ind1-1,ind2-1,dp)});
    }
        
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(s,t,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends