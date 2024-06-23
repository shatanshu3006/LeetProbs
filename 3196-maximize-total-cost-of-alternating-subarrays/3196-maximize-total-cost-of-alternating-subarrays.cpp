class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<long long>dp(n+1,0);
        dp[1]=nums[0];
        for(int i=1;i<nums.size();i++){
            long long option1=dp[i]+nums[i];    //for both positive and negative nums[i]
            long long option2=dp[i-1]+nums[i-1]+(-1*nums[i]);

            dp[i+1]=max(option1,option2);
        }
        return dp[n];
    }
};