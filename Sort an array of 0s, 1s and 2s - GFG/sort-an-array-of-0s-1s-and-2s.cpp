//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)cnt0++;
            if(a[i]==1)cnt1++;
            if(a[i]==2)cnt2++;
        }
        int i=0;
        while(cnt0--)
        {
            a[i]=0;
            i++;
            
        }
        while(cnt1--)
        {
            a[i]=1;
            i++;
            
        }
        while(cnt2--)
        {
            a[i]=2;
            i++;
            
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends