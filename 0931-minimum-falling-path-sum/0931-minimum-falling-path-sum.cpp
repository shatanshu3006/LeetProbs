class Solution {
public:
   //tabulation approach
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int top = INT_MAX, leftd = INT_MAX, rightd = INT_MAX;
                if(i-1 >= 0) top = dp[i-1][j];
                if(i-1 >= 0 && j-1>=0) leftd = dp[i-1][j-1];
                if(i-1 >= 0 && j+1<m) rightd = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(top, min(leftd, rightd));
                
            }
        }
        int res = INT_MAX;
        for(int col = 0; col<m; col++){
            res = min( dp[n-1][col], res);
        }
        return res;
    }
};