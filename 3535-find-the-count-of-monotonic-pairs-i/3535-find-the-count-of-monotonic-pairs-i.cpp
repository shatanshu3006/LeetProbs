class Solution {
public:
const int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,-1));
        return func(0,0,nums,dp);
    }
    int func(int i,int prev,vector<int>&nums, vector<vector<int>>&dp){
        if(i>=nums.size())return 1;
        if(dp[i][prev]!=-1)return dp[i][prev];

        int c=0;
        for(int val=prev;val<=nums[i];val++){
            int k=nums[i]-val;

            if(i==0 || k<=nums[i-1]-prev){
                c=(c+func(i+1,val,nums,dp))%mod;
            }
        }
        return dp[i][prev]=c;
    }
};