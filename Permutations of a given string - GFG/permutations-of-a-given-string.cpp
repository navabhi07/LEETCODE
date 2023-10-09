//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void solve(set<string>& ans,int ind,string s){
        if(ind>=s.size()){
            ans.insert(s);
            return;
        }
        
        for(int i = ind;i<s.size();i++){
            
              swap(s[ind],s[i]);
              solve(ans,ind+1,s);
              swap(s[ind],s[i]);
            
        }            
        
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    sort(S.begin(),S.end());
		    int ind = 0;
		    solve(ans,ind,S);
		    vector<string> res(ans.begin(),ans.end());
		    return res;
		    
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends