//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
     bool ok(vector<long long> v, long long n,long long mid, long long x)
    {
        bool ans;
        for(long long i=0;i<n;i++)
        {
            if(v[mid]<=x)ans=true;
            else ans=false;
        }
        return ans;
    }
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        if(n==1)
        {
            if(v[0]<=x)return v[0];
            else return -1;
        }
        int l=-1,h=n-1;
        while(l+1<h)
        {
            int mid=l+(h-l)/2;
            if(ok(v,n,mid,x))l=mid;
            else h=mid;
        }
        if(v[h]<=x)return h;
        else return l;
       
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends