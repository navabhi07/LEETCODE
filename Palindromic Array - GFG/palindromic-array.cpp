//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
bool f(string s)
{
    int i=0,j=s.size()-1;
    //int cnt=0;
    while(j>i)
    {
        if(s[i]!=s[j])
        {
            return false;
            break;
        }
        i++;
        j--;
    }
    return true;
}
    int PalinArray(int a[], int n)
    {
    	// code here
    	int cnt=0;
    	for(int i=0;i<n;i++)
    	{
    	    int p=a[i];
    	    string g=to_string(p);
    	    
    	    if(!f(g))
    	    {
    	        cnt=1;
    	        break;
    	    }
    	}
    	if(cnt==1)return 0;
    	else return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends