class Solution {
public:
typedef long long ll;
ll func(vector<int>&nums,int index,bool flag,vector<vector<ll>>&dp){
    int n=nums.size();
    if(index>=n){
        return 0;
    }
    if(dp[index][flag]!=-1){
        return dp[index][flag];
    }
    ll take=LLONG_MIN,not_take=LLONG_MIN;
    if(flag==false){    //negative sign (for subarray cost)
        not_take=(-nums[index]+func(nums,index+1,true,dp));
    }
    //positive sign 
    take=nums[index]+func(nums,index+1,false,dp);
    return dp[index][flag]=max(take,not_take);
}
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        //two possibilities of flag->true and false (take and not_take)
        vector<vector<ll>>dp(n+1,vector<ll>(3,-1));
        //print(dp);
        return func(nums,0,false,dp);
        
    }
    //for the first test case the table looks like:

//initially ->
//            true(0)  false(1)  (3)
//        0      -1      -1      -1
//        1      -1      -1      -1
//        2      -1      -1      -1
//        3      -1      -1      -1
//        4      -1      -1      -1       

//finally ->
//            true(0)  false(1)  (3)
//        0      -1       10     -1
//        1       8       9      -1
//        2       7       7      -1
//        3      -4       4      -1
//        4      -1      -1      -1  


};