//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

bool ok(int arr[],int mid,int n,int x)
{
    bool ans;
    for(int i=0;i<n;i++)
    {
        if(arr[mid]<=x)ans=true;
        else ans=false;
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    //int lower=0,higher=0;
    if(n==1)
    {
        int lower,higher;
        if(arr[0]>x)
        {
            lower=-1;
            higher=arr[0];
        }
        else 
        {
            lower=arr[0];
            higher=-1;
        }
        pair<int,int>p{lower,higher};
        return p;
        
    }
    
    int l=-1,h=n-1;
     //int lower,higher;
    while(l+1<h)
    {
        int mid=l+(h-l)/2;
        if(ok(arr,mid,n,x))l=mid;
        else h=mid;
    }
    int lower,higher;
    if(arr[h]<=x)lower=arr[h];
    else if(l==-1)lower=-1;
    else lower=arr[l];
    //l=-1,h=n-1;
    //  while(l+1<h)
    // {
    //     int mid=l+(h-l)/2;
    //     if(ok(arr,mid,n,x))h=mid;
    //     else l=mid;
    // }
    if(arr[l]==x)higher=arr[l];
    else if(arr[h]<x)higher=-1;
    else higher=arr[h];
    
    
    pair<int,int>p{lower,higher};
    //p[0]=;
    return p;
    
    
}