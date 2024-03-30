class Solution {
public:
int atMost(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    int i=0,j=0,n=nums.size(),ans=0;

    while(j<n){
        mp[nums[j]]++;
        while(mp.size()>k && i<=j){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=atMost(nums,k)-atMost(nums,k-1);
        return ans;
    }
};