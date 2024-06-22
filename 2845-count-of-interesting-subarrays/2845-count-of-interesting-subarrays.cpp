class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        #define ll long long
        map<ll,ll>mp;
        mp[0]=1;
        int n=nums.size(); ll ans=0,prefix=0;
        for(int it:nums){
            if(it%modulo==k){
                prefix++;
            }
            ans+=mp[(prefix-k)%modulo];
            mp[prefix%modulo]++;
        }
        return ans;
    }
};