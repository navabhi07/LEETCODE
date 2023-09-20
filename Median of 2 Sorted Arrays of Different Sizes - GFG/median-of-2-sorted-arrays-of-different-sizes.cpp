//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        // Your code goes here
        //int i=0,j=0;
        int n=a1.size(),m=a2.size();
           int i=0,j=0;
          // double ans=0;
          vector<int>v;
        while(i<n&&j<m)
        {
            if(a1[i]<a2[j])
            {
                // swap(a1[i],a2[j]);
                // i--;
                // j++;
                v.push_back(a1[i++]);
                
                
            }
            else
            {
               // i--;
                v.push_back(a2[j++]);
               
            }
            
        }
        while(i<n)v.push_back(a1[i++]);
        while(j<m)v.push_back(a2[j++]);
        
        int q=(n+m)/2;
        if((n+m)&1)return v[q];
        else
        {
           
            double ans=(double(v[q-1]+v[q])/2);
             return ans; 
        }
        
       
        
        
            
            
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends