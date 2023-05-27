//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	 bool ok(int a,int b)
	 {
	     if(a>=b)return true;
	     else return false;
	 }
	 bool ok1(int a,int b)
	 {
	     if(a<=b)return true;
	     else return false;
	 }
	int first(int arr[],int n,int x)
	{
	    int l=-1,h=n;
	    while(l+1<h)
	    {
	        int mid=l+(h-l)/2;
	        if(ok(arr[mid],x))h=mid;
	        else l=mid;
	    }
	    if(h==n||arr[h]!=x)return -1;
	    else return h;
	}
	
	int last(int arr[],int n,int x)
	{
	    int l=-1,h=n;
	    while(l+1<h)
	    {
	        int mid=l+(h-l)/2;
	        if(ok1(arr[mid],x))l=mid;
	        else h=mid;
	    }
	    if(l==-1||arr[l]!=x)return -1;
	    else return l;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int fi=first(arr,n,x);
	    int la=last(arr,n,x);
	    if(la==-1&&fi==-1)return 0;
	    else
	    return (la-fi)+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends