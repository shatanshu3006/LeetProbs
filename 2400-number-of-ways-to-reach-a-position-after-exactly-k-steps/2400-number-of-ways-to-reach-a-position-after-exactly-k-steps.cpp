class Solution {
public:
const int mod=1e9+7;
int find(int start,int end,int k,vector<vector<int>>&dp){
    if(k==0){
        if(start==end)return 1;
        else return 0;
    }
    if(dp[start][k]!=-1)return dp[start][k]%mod;
    int forward=find(start+1,end,k-1,dp)%mod;
    int backward=find(start-1,end,k-1,dp)%mod;

    return dp[start][k]=(forward+backward)%mod;
}
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3003,vector<int>(1001,-1));
        return find(startPos+k,endPos+k,k,dp);
    }
};