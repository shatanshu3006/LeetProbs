class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,minp=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minp=min(prices[i],minp);
            profit=max(profit,prices[i]-minp);
        }
        return profit;
    }
};