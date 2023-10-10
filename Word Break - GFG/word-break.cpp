//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    
bool f(unordered_set<string>&st,string s,int ind,vector<int>&dp)
{
    if(ind==s.size())return true;
    if(dp[ind]!=-1)return dp[ind];
    if(st.find(s)!=st.end())return true;
    
    for(int l=1;l<=s.size();l++)
    {
        string temp=s.substr(ind,l);
        if(st.find(temp)!=st.end()&&f(st,s,ind+l,dp))return dp[ind]=true;
    }
     return dp[ind]= false;
}
public:
    int wordBreak(string a, vector<string> &B) {
        //code here
        unordered_set<string>st;
        for(int i=0;i<B.size();i++)st.insert(B[i]);
        vector<int>dp(a.size(),-1);
        bool ans=f(st,a,0,dp);
        if(ans==true)return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends