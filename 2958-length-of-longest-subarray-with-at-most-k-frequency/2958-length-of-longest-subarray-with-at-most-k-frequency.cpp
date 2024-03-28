class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        
        for(int l=0,r=0;r<n;r++){
            mp[nums[r]]++;

            if(mp[nums[r]]>k){
                while(nums[l]!=nums[r]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
            }
};