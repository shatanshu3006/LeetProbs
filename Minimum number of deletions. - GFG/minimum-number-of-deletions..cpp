//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string str, int n) { 
    //complete the function here 
    string R = str;
    reverse(R.begin(), R.end());
 
    // dp[i][j] will store the length of the longest
    // palindromic subsequence for the substring
    // starting at index i and ending at index j
    int dp[str.length() + 1][R.length() + 1];
 
    // Initialize dp array with zeros
    memset(dp, 0, sizeof(dp));
 
    // Filling up DP table based on conditions discussed
    // in the above approach
    for (int i = 1; i <= str.length(); i++) {
        for (int j = 1; j <= R.length(); j++) {
            if (str[i - 1] == R[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
 
    // At the end, DP table will contain the LPS
    // So just return the length of LPS
    return n-dp[str.length()][R.length()];
} 