
class Solution {
public:

int solve(int n,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int res=1e9;
    for(int i=1;i*i<=n;i++){
        int pick=1+solve(n-i*i,dp);
        res=min(res,pick);
    }
    return dp[n]=res;
}
    int numSquares(int n) {
        vector<int>dp(10001,-1);
        return solve(n,dp);
    }
};