class Solution {
public:
int func(int ind,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    int profit=0;

if(dp[ind][buy]!=-1){
    return dp[ind][buy];
}
    if(buy){
        // - prices[ind] is because we have to give money inorder to buy a stock and that reduces the total profit CURRENTLY sice we are giving up the money 
        // then in later future we mught end up with buying other stock rather than this
        profit=max(-prices[ind] + func(ind+1,0,prices,n,dp) , 0 + func(ind+1,1,prices,n,dp));
    }

    // now incase of selling, if we want to sell a stock right NOW, then we GAIN +prices[ind], and then buying in the bext recursoin calls is available so buy=1
    // if we dont want to sell right NOW, then 0 profit + BUY=0 call in recursive functoin as we can't buy unless we sell 
    else{
        profit=max(prices[ind] + func(ind+1,1,prices,n,dp) , 0 + func(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // the recursive function starts with buying a stock since if we don't buy then the game wont 
        //start at all 
        //so buy=1 in the first recursoin call

        //memoization
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,1,prices,n,dp);
    }
};