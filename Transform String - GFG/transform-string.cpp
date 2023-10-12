//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        unordered_map<char,int>mp;
        for(auto it:a)mp[it]++;
        for(auto it:b)mp[it]--;
        for(auto it:mp)if(it.second!=0)return -1;
        int i=a.size()-1,j=b.size()-1,ans=0;
        while(i>=0&&j>=0)
        {
            if(a[i]==b[j])
            {
                i--;
                j--;
            }
            else
            {
                ans++;
                i--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends