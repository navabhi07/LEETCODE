//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int p=0,q=0,r=0;
        if(n==1)return arr;
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1]>arr[i])
            {
               p=i;
               q=i+1;
               break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>arr[p])
            {
                r=i;
                break;
            }
        }
        swap(arr[p],arr[r]);
        reverse(arr.begin()+q,arr.end());
        
        return arr;
        
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends