class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        //dp[i][j] - stores best length starting at j and nums[j] (for our map), and i decrements were used.
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        //map<int, int> - stores best length if we reuse same number (with that number able to decrement K).
        map<int,int>prev;
        //int change - stores best length if we decrement K.
        int change=0;


        //Starting from K = 0, start from the end of the array, and keep track of two numbers.

// Best length, if we decremented K.
// Best length, if we reused the same number (but that future i can decrement K).
         for(int i=0;i<=k;i++){
            prev.clear();
            change=0;
            //j iterates over nums
            for(int j=n-1;j>=0;j--){
                int num=nums[j];
                int reuse=0;
                if(prev[num]!=NULL){
                    reuse=prev[num];
                }

                dp[i][j]=1+max(change,reuse);

                if(i>0){
                    change=max(change,dp[i-1][j]);
                }
                prev[num]=dp[i][j];
            }
        }

        int best=0;
        for(int num:dp[k]){
            best=max(best,num);
        }
        return best;
    }
};