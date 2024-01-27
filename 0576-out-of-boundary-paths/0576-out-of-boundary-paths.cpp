class Solution {
public:
int mod=1e9+7;
int func(int n,int m,int maxMove,int startRow,int startColumn,vector<vector<vector<int>>>&dp){
    if(startColumn<0 || startColumn>=n || startRow<0 || startRow>=m){
        return 1;
    }
    if(maxMove==0)return 0;
    if(dp[startRow][startColumn][maxMove]!=-1){
        return dp[startRow][startColumn][maxMove];
    }

    int up=0,down=0,left=0,right=0;
    if(maxMove>0){
        up=func(n,m,maxMove-1,startRow-1,startColumn,dp);
    }
    if(maxMove>0){
        down=func(n,m,maxMove-1,startRow+1,startColumn,dp);
    }
    if(maxMove>0){
        left=func(n,m,maxMove-1,startRow,startColumn-1,dp);
    }
    if(maxMove>0){
        right=func(n,m,maxMove-1,startRow,startColumn+1,dp);
    }
    return dp[startRow][startColumn][maxMove]= ((up+down)%mod+(left+right)%mod)%mod;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return func(n,m,maxMove,startRow,startColumn,dp);
    }
};