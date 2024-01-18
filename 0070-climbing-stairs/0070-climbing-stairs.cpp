class Solution {
public:

int solve(int ind,vector<int>&dp,int n){
    if(ind>n)return 0;
    if(ind==n)return 1;

    if(dp[ind]!=-1)return dp[ind];

    int take=solve(ind+1,dp,n);
    int not_take=solve(ind+2,dp,n);
    return dp[ind]=take+not_take;
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(0,dp,n);
    }
};