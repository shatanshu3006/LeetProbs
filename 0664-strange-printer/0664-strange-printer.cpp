class Solution {
public:
int func(int start,int end,string &s,vector<vector<int>>&dp){
    if(start>end)return 0;
    if(dp[start][end]!=-1)return dp[start][end];

    int steps=1+func(start+1,end,s,dp);
    for(int k=start+1;k<=end;k++){
        if(s[k]==s[start]){
            steps=min(steps,func(start,k-1,s,dp)+func(k+1,end,s,dp));
        }
    }
    return dp[start][end]=steps;
}
    int strangePrinter(string s) {
        //We use a 2-D array memo, where memo[start][end] stores the minimum turns for the substring from start to end.
        int n=s.length();
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return func(0,n-1,s,dp);
    }
};