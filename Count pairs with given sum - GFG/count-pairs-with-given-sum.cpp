//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int v=k-arr[i];
            if(v==arr[i])
            {
                if(m[v]>0)
                {
                cnt+=(m[arr[i]]*(m[arr[i]]-1))/2;
                m.erase(arr[i]);
                }
                
            }
            else 
            {
                if(m[v]>0)
                {
                cnt+=m[v]*m[arr[i]];
                m.erase(v);
                m.erase(arr[i]);
                }
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends