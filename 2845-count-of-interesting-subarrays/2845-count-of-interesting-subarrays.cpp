class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        //creating a binary vector v
        vector<int>cnt;
        for(auto it:nums){
            if(it%modulo==k){
                cnt.push_back(1);
            }
            else{
            cnt.push_back(0);
            }
        }
        int prefix_sum=0;
        map<int,int>mp;
        mp[0]=1;
        long long ans=0;
        for(auto it:cnt){
            prefix_sum+=it;
            ans+=mp[((prefix_sum-k)%modulo + modulo)%modulo];
            mp[((prefix_sum)%modulo + modulo)%modulo]++;
        }
        return ans;
    }
};