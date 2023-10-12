//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here 
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            
            
        }
        int p=m.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int ans=1e9;
        while(j<s.size())
        {
            if(mp.size()<p)
            {
                mp[s[j]]++;
                //j++;
            }
            
        
                
                while(mp.size()==p)
                {
                    mp[s[i]]--;
                  
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    ans=min(ans,(j-i+1));
                      i++;
                }
                //ans=min(ans,(j-i+1));
                //j++;
            
           j++;
        }
         
        return ans;
        
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends