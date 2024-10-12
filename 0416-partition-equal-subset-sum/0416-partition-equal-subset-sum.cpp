class Solution {
public:
//recursive appraoch
bool func(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(ind==0){
        return nums[0]==target;
    }
    if(target==0){
        return true;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int not_take=func(ind-1,target,nums,dp);
    int take=0;
    if(target>=nums[ind]){
        take=func(ind-1,target-nums[ind],nums,dp);
    }
    return dp[ind][target]=take||not_take;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            int target=sum/2;
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return func(n-1,target,nums,dp);
        }
    }
};