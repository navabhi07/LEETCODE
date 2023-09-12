//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int l=0,h=n-1;
        int ans[n];
        for(int i=0;i<n;i++)ans[i]=0;
        int i=0,j=0;
       while(i<n)
       {
           if(arr[i]>0)
           {
               ans[j]=arr[i];
               j++;
           }
           i++;
       }
       i=0;
         while(i<n)
         {
             if(arr[i]<0)
             {
                 ans[j]=arr[i];
                 j++;
             }
             i++;
         }
         for(int k=0;k<n;k++)
         {
             arr[k]=ans[k];
         }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends