//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string S) {
       string R = S;
    reverse(R.begin(), R.end());
 
    // dp[i][j] will store the length of the longest
    // palindromic subsequence for the substring
    // starting at index i and ending at index j
    int dp[S.length() + 1][R.length() + 1];
 
    // Initialize dp array with zeros
    memset(dp, 0, sizeof(dp));
 
    // Filling up DP table based on conditions discussed
    // in the above approach
    for (int i = 1; i <= S.length(); i++) {
        for (int j = 1; j <= R.length(); j++) {
            if (S[i - 1] == R[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
 
    // At the end, DP table will contain the LPS
    // So just return the length of LPS
    return dp[S.length()][R.length()];
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