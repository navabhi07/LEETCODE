//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    static int cmp(int a ,int b)
    {
        int c1= __builtin_popcount(a);
        int c2= __builtin_popcount(b);
        
        if(c1<=c2)return false;
        else return true;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
       
        stable_sort(arr,arr+n,cmp);
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends