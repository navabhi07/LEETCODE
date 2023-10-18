//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    set<vector<long long >>st;
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        long long  p=arr[i];
	        vector<long long >ans;
	        long long l=i+1,h=n-1;
	        long long  val=sum-p;
	        while(h>l)
	        {
	            if(arr[l]+arr[h]==val)
	            {
	               // ans.push_back(p);
	               // ans.push_back(arr[l]);
	               // ans.push_back(arr[h]);
	                
	                h--;
	               // st.insert(ans);
	               // ans.clear();
	            }
	            else if(arr[l]+arr[h]>val)h--;
	            else
	            {
	                cnt+=(h-l);
	                l++;
	            }
	        }
	      
	        
	    }
	    return cnt;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends