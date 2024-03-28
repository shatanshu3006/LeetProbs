class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int n=nums.size();

        int l=0,r=0;
        
        while(r<n){
            mp[nums[r]]++;
            while(l<r && mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
            }
};