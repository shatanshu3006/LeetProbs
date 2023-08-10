//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    long long int count(int coins[], int n, int sum) {

        // code here.
        //memooizations
        // long long int sum = accumulate(coins, coins+n, 0LL);
        vector<vector<long long int>>dp(n,vector<long long int>(sum+1,0));
        for(int i=0; i<=sum; i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0; j<=sum; j++){
                long long not_take=dp[i-1][j];// func(ind-1,target,coins,dp);
                long long take=0;
                if(coins[i]<=j){
                    take=dp[i][j-coins[i]];//func(ind,target-coins[ind],coins,dp);
                }
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends