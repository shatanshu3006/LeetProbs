//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int func(int ind,int target,int coins[],vector<vector<long long int>>&dp){
      if(ind==0){
          return (target%coins[0]==0);
      }
      if(dp[ind][target]!=-1){
          return dp[ind][target];
      }
      long long not_take=func(ind-1,target,coins,dp);
      long long take=0;
      if(coins[ind]<=target){
          take=func(ind,target-coins[ind],coins,dp);
          
      }
      return dp[ind][target]=take+not_take;
  }
    long long int count(int coins[], int n, int sum) {

        // code here.
        //memooizations
        // long long int sum = accumulate
        // if we declare the value of 1001 instead of sum+1 
        // then at the initial cases it will give tle 
        // so utna hi declare kro jitne ki test case me jarurat hai 
        // which means sum+1 and not highest 1001 for every test case
        vector<vector<long long int>>dp(n,vector<long long int>(sum+1,-1));
        // for()
        // for(int i=0;i<n-1;i++){
            
        // }
        return func(n-1, sum, coins, dp);
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