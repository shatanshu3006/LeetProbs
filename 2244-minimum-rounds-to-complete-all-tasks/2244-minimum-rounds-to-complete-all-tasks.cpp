class Solution {
public:
//When we look at the problem we can instantly say that 
// it is coin change problem where we have only coins 
// of 2 and 3 and we want to use minimum number 
// of coins for the frequency of every element.

int coinchange(int total_sum,vector<int>&dp){
    if(total_sum==2 || total_sum==3)return 1;

    if(total_sum==1)return 100005;

    if(dp[total_sum]!=-1)return dp[total_sum];

    int a=INT_MAX;
    if(total_sum>=2){
        a=min(a,coinchange(total_sum-2,dp)+1);
    }
    if(total_sum>=3){
        a=min(a,coinchange(total_sum-3,dp)+1);
    }

    return dp[total_sum]=a;
}
    int minimumRounds(vector<int>& tasks) {
        vector<int>dp(100005,-1);
        map<int,int>mp;
        for(auto it:tasks)mp[it]++;
        vector<int>arr;
        for(auto it:mp)arr.push_back(it.second);

int ans=0;
        for(int i=0;i<arr.size();i++){
            int curr=coinchange(arr[i],dp);
            if(curr>=100005)return -1;
            else{
                ans+=curr;
            }
        }
        return ans;
    }
};