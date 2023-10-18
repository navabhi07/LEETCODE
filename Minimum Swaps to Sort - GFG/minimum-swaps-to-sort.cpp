//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int>mp;
	    for(int i=0;i<nums.size();i++)mp[nums[i]]=i;
	    vector<int>res;
	    res=nums;
	    sort(res.begin(),res.end());
	    int cnt=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        if(res[i]!=nums[i])
	        {
	            cnt++;
	            int act_pos=mp[res[i]];
	            mp[nums[i]]=act_pos;
	            swap(nums[i],nums[act_pos]);
	            
	           
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends