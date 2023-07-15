//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int func(string str,int i,int j,vector<vector<int>>&dp){
      int n=str.length();
      //only one character so one is the longest
      if(i==j){
          return 1;
      }
      //if the adjacent are same
      if(str[i]==str[j] && i+1==j){
          return 2;
      }
      //if they are apart and same
      if(str[i]==str[j]){
          return func(str,i+1,j-1,dp)+2;       //+2 for being found and func for further index
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      
      
      //if they dont match and are far apart
      //move i+1 by j const and move j-1 by i const and find the maximum of that
      return dp[i][j]=max(func(str,i+1,j,dp),func(str,i,j-1,dp));
      
  }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.length();
        //we need starting index,ending index and string 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(A,0,n-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends