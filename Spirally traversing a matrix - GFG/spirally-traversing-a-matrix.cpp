//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        int count=0;
        int total=r*c;
        int strtcol=0;
        int endcol=c-1;
        int strtrow=0;
        int endrow=r-1;
        vector<int>ans;
        while(count<total)
        {
          for(int i=strtcol;count<total&&i<=endcol;i++)
          {
              ans.push_back(mat[strtrow][i]);
              count++;
          }
          strtrow++;
          for(int i=strtrow;count<total&&i<=endrow;i++)
          {
              ans.push_back(mat[i][endcol]);
              count++;
          }
          endcol--;
          for(int i=endcol;count<total&&i>=strtcol;i--)
          {
              ans.push_back(mat[endrow][i]);
              count++;
          }
          endrow--;
          for(int i=endrow;count<total&&i>=strtrow;i--)
          {
              ans.push_back(mat[i][strtcol]);
              count++;
          }
          strtcol++;;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends