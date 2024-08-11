class Solution {
    int mod = 1e9 + 7; // Modulus for large numbers to avoid overflow
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, 0)); // DP table to store subsequence counts

        // Initialize DP table for the first element
        for(int j = 0; j <= nums[0]; ++j) {
            dp[0][j] = 1;
        }

        // DP transition to fill the table
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] < nums[i]) {
                // Case where nums[i-1] < nums[i]
                int diff = nums[i] - nums[i - 1];
                int sum = 0;
                for(int j = diff; j <= nums[i]; ++j) {
                    sum = (sum + dp[i - 1][j - diff]) % mod; // Accumulate valid subsequences
                    dp[i][j] = sum; // Store the count in the DP table
                }
            } else {
                // Case where nums[i-1] >= nums[i]
                int sum = 0;
                for(int j = 0; j <= nums[i]; ++j) {
                    sum = (sum + dp[i - 1][j]) % mod; // Accumulate valid subsequences
                    dp[i][j] = sum; // Store the count in the DP table
                }
            } 
        }

        // Sum up all valid subsequences ending at the last element
        long ans = 0;
        for(int j = 0; j < 1001; ++j) {
            ans = (ans + dp[n - 1][j]) % mod; // Sum all the values in the last row of DP table
        }

        return ans; // Return the final count
    }
};