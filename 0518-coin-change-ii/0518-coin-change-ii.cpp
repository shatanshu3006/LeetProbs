class Solution {
public:
//MEMOIZATION APPROACH
int func(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        return target%coins[0]==0;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int not_take=0+func(ind-1,target,coins,dp);
    int take=0;
    if(coins[ind]<=target){
        //since the number of coins is infinite we remain on the same index 
        //as long as the condition is fulfilled
        // eg: 4=1+1+1+1;
        take=func(ind,target-coins[ind],coins,dp);
    }
    return dp[ind][target]=take+not_take;
}
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(n-1,amount,coins,dp);
    }
};