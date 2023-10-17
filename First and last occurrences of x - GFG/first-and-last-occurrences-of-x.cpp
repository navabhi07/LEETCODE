//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool f(int a,int b)
    {
        if(a<=b)return true;
        else return false;
    }
     bool f1(int a,int b)
    {
        if(a>=b)return true;
        else return false;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int l=0,h=n-1;
        int ans1=-1,ans2=-1;
        while(h>=l)
        {
            int mid=l+(h-l)/2;
            if(arr[mid]>x)
            {
                h=mid-1;
                
                
            }
            else if(arr[mid]==x)
            {
                ans1=mid;
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        l=0,h=n-1;
         while(h>=l)
        {
            int mid=l+(h-l)/2;
            if(arr[mid]<x)
            {
                l=mid+1;
                
                
            }
            else if(arr[mid]==x)
            {
                ans2=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        vector<int>v;
        //if(v[ans1]==x&&ans1!=-1)
        if(ans1==-1||ans2==-1)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
        v.push_back(ans1);
        //else  v.push_back(-1); 
       // if(v[ans2]==x&&ans2!=-1)
        v.push_back(ans2);
        }
        //else v.push_back(-1);
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends