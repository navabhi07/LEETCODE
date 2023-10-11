//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int p=s.size();
   string a ,b;
    for(int i=0;i<p;i++)
    {
        if(!(i&1))
        {
           a.push_back('0') ;
           b.push_back('1');
        }
        else
        {
            a.push_back('1');
            b.push_back('0');
        }
        
        
    }
    //cout<<a<<" "<<b;
    int cnt=0,snt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=a[i])cnt++;
        if(s[i]!=b[i])snt++;
    }
    return min(cnt,snt);
}