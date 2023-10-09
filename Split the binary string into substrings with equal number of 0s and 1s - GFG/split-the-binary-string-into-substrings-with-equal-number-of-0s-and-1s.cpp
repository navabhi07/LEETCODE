//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        if(str.size()==1)return -1;
        int z=0,o=0;
        int cnt=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0')z++;
            if(str[i]=='1')o++;
            if(z==o)
            {
                cnt++;
                z=0;
                o=0;
            }
            
        }
        if(cnt==0||z!=o)return -1;
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends