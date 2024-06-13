class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0,maxcount=0,n=nums.size();
        while(r<n){
            if(nums[r]==0){
                l=r+1;
            }
            maxcount=max(maxcount,r-l+1);
            r++;
        }
        return maxcount;
    }
};