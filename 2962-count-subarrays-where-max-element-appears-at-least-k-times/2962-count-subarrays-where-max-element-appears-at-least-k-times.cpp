class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int l=0,r=0;
        long long ans=0;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;

            while(mp[maxi]>=k){
                mp[nums[l]]--;
                //addin the count of subarrays from l to end ptr (n-1)
                //as all subarrays will have atleast k occurence of maxi
                ans+=(n-1)-r+1;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};