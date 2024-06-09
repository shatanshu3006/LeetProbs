class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMostSum(nums,goal)-slidingWindowAtMostSum(nums,goal-1);
    }
    int slidingWindowAtMostSum(vector<int>&nums,int goal){
        int n=nums.size();
        int left=0;
        int right=0;
        int currentSum=0;
        int totalCount=0;

        //iterating thrugh sliding window appraoch
        while(right<n){
            currentSum+=nums[right];

            while(currentSum>goal && left<=right){
                currentSum-=nums[left];
                left++;
            }
// all the length of subarry thus found is added 
// agar i se j tak subarray hai , nums[i]....nums[j]
// then for a sum lessthan or equal to goal , nums[i], nums[i]..nums[i+1],num[i]...nums[i+2]... , nums[i]...nums[j] tak sabhi wo subarrays hain jinka sum<=goal hai 
// so we directly add the length of subarray to our ans 
            totalCount+=(right-left+1);
            right++;
        }
        return totalCount;
    }
};