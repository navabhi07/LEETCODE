//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
     
        vector<int> left(n, 0);
      
        // right[i] contains height of tallest bar to 
        // the right of bar at ith index including itself. 
        vector<int> right(n, 0); 
      
        long long water = 0;
      
        // Storing values of tallest bar from first index till ith index.
        left[0] = arr[0];
        for (int i = 1;i < n;i++) {
            left[i] = max(left[i - 1], arr[i]);
        }
      
        // Storing values of tallest bar from last index till ith index. 
        right[n-1] = arr[n-1]; 
        for (int i = n - 2;i >= 0;i--) {
            right[i] = max(right[i + 1], arr[i]);
        }
    
       
        for (int i = 0;i < n;i++) {
            water += max(0, min(left[i], right[i]) - arr[i]);
        }
    
        return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends