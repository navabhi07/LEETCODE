//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>v;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            vector<int>ans;
            int p=arr[i];
            
            for(int j=i+1;j<n;j++)
            
            {
                int q=arr[j];
                int val=k-(p+q);
                int l=j+1,h=n-1;
                while(h>l)
                {
                    if(arr[l]+arr[h]==val)
                    {
                        ans.push_back(p);
                        ans.push_back(q);
                        ans.push_back(arr[l]);
                        ans.push_back(arr[h]);
                        l++;
                        h--;
                        st.insert(ans);
                        ans.clear();
                    }
                    else if(arr[l]+arr[h]>val)h--;
                    else l++;
                }
                
            }
        }
        for(auto it:st)v.push_back(it);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends