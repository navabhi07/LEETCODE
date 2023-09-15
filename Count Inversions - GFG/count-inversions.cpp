//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long low, long long mid, long long high, long long &ans, long long arr[]){
        long long i = low, j = mid+1;
        vector<long long> temp;
        while(i<=mid and j<=high){
            if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
            else{
                ans += mid-(i-1);
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=high) temp.push_back(arr[j++]);
        for(long long k = 0; k < temp.size(); k++){
            arr[k+low] = temp[k];
        }
    }
    void merge_sort(long long low, long long high, long long &ans, long long arr[]){
        if(low >= high) return;
        long long mid = (high-low)/2 + low;
        merge_sort(low, mid, ans, arr);
        merge_sort(mid+1, high, ans, arr);
        merge(low, mid, high, ans, arr);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = 0;
        merge_sort(0, N-1, ans, arr);
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends