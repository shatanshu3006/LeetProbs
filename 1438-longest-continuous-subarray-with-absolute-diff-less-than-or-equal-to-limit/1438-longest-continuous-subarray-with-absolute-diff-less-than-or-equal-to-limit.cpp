class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       int n=nums.size();
       int l=0,r=0;
       map<int,int>mp;
       int maxi=1;
       while(r<n){
        mp[nums[r]]++;
        while(l<r && abs(mp.begin()->first-mp.rbegin()->first)>limit){
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
        }
        maxi=max(maxi,r-l+1);
        r++;
       }
       return maxi;
    }
};