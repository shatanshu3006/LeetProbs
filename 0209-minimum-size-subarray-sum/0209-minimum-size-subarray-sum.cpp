class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size(),sum=0,ans=INT_MAX;
        while(r<n){
            sum+=nums[r];
                while(sum>=target && l<=r){
                    sum-=nums[l];
                    ans=min(ans,r-l+1);
                    l++;
                }
            
            r++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};