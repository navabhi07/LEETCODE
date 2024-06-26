//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
      sort(a.begin(),a.end());
      //for(auto it:a)cout<<it<<" ";
     long long i=0,j=0,mini=INT_MAX;
      while(j<n)
      {
          if(j-i+1<m)j++;
          if(j-i+1==m)
          {
              mini=min(mini,a[j]-a[i]);
              i++;
              j++;
          }
      }
      return mini;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends