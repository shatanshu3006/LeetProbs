class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mini=prices[0];
        for( int i=0;i<prices.size();i++){
            int currprofit=prices[i]-mini;
            maxprofit=max(maxprofit,currprofit);
            mini=min(mini,prices[i]);
        }
        return maxprofit;
    }
};