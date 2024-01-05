class Solution {
public:
int func(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }
    int len=0+func(ind+1,prev_ind,nums,n,dp);
    if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
        len=max(len,1+func(ind+1,ind,nums,n,dp));
    }
    return dp[ind][prev_ind+1]=len;
}
    int lengthOfLIS(vector<int>& nums) {
        //memo approach
        int n=nums.size();
        //coordinate shifting for values of prev_ind =-1
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,n,dp);
    }
};