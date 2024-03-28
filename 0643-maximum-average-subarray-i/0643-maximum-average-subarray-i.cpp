class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currsum=0,maxsum=0;
int n=nums.size();
        for(int i=0;i<k;i++){
            currsum+=nums[i];
        }

        maxsum=currsum;
        // Start the loop from the kth element 
        // Iterate until you reach the end

        for(int i=k;i<n;i++){
             // Subtract the left element of the window
            // Add the right element of the window

            //standars sliding window for adding and then subtracting the ones 
            currsum+=nums[i]-nums[i-k];

            maxsum=max(maxsum,currsum);
        }
        return maxsum/k;
    }
};