class Solution {
public:
//to solve this problem like in the previous similar que part 2, we can just include a counter of cap 
//on the total number if transactoins allowed , that is 2
// if we buy and if the selling for that purchase is complete then we simply change the cap variable
int func(int ind,int buy,int count,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
    if(count==0){
        return 0;
    }
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy][count]!=-1){
        return dp[ind][buy][count];
    }
    int profit=INT_MIN;
    if(buy){
        //no change in the counter here as the transaction has not been completed
        profit=max(-prices[ind] + func(ind+1,0,count,prices,n,dp) , 0 + func(ind+1,1,count,prices,n,dp));
    }
    else{
        profit=max(prices[ind] + func(ind+1,1,count-1,prices,n,dp) , 0 + func(ind+1,0,count,prices,n,dp));
    }
    return dp[ind][buy][count]=profit;
}


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,prices,n,dp);
    }
};