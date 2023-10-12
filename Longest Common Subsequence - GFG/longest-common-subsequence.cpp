//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int n,int m,int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp)
    {
        if(ind1<0||ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])return 1+f(n,m,ind1-1,ind2-1,s1,s2,dp);
        else
        {
            return max(f(n,m,ind1-1,ind2,s1,s2,dp),f(n,m,ind1,ind2-1,s1,s2,dp));
        }
    }
    
    
    
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
        
        //return f(n,m,n-1,m-1,s1,s2,dp);
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends