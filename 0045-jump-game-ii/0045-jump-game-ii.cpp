class Solution {
public:
int solve(int ind,vector<int>&nums,vector<int>&dp){
    if(ind>=nums.size()-1)return 0;
    if(dp[ind]!=-1)return dp[ind];

    int ans=INT_MAX/2;

    for(int i=1;i<=nums[ind];i++){
        if(ind+i<nums.size()-1 && dp[ind+i]!=-1){
            ans=min(ans,1+dp[ind+i]);
        }
        else{
            ans=min(ans,1+solve(ind+i,nums,dp));
        }
    }
    return dp[ind]=ans;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);//init dp array with -1
        return solve(0,nums,dp);   //start recursion from 0
    }
};