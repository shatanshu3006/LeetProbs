class Solution {
public:
int mod=1e9+7;
    int func(int n,int k,vector<vector<int>>&dp){
        if(k<=0){
            return k==0;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=func(n-1,k-i,dp);
            ans=ans%mod;
        }
        return dp[n][k]=ans;
    }
//tabulation appraoch
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int N=0;N<=n;N++){
            dp[N][0]=1;
        }
        for(int N=1;N<=n;N++){
            for(int K=0;K<=k;K++){
                int ans=0;
                for(int i=0;i<min(N,K+1);i++){
                    ans+=dp[N-1][K-i];
                    ans=ans%mod;
                }
                dp[N][K]=ans;
            }
        }
        return dp[n][k];
    }
};