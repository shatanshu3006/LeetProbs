class Solution {
public:
#define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        map<ll,ll>mp;
        ll ans=0,prefix=0,n=nums.size();
        mp[0]=1;

        //we will take prefix sum of nums[i]%modulo ==k
        // [3,1,9,6] --(k==0,modulo==3)--> [1,0,1,1]
        // prefix sum => [1,1,2,3] if its count==k till index i

        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                prefix++;
            }
            prefix=prefix%modulo;
            if(mp.find((prefix-k+modulo)%modulo)!=mp.end()){
                ans+=mp[(prefix-k+modulo)%modulo];
            }
            mp[prefix]++;
        }
        return ans;
    }
};