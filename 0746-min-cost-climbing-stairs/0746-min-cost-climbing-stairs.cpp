class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        //i cannot stand on index n and calculate as i can finally jump on it from either n-1 or n-2 depending upon how much cost has incurred.Moreover, there is no value at index n i ncost vector
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};