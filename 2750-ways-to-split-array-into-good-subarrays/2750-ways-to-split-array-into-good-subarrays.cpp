class Solution {
public:
int mod=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int>split;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                split.push_back(i);
            }
        }
        if(split.size()==0)return 0; // no ones present
        long long int cnt=1;
        for(int i=1;i<split.size();i++){
            cnt*=(split[i]-split[i-1])%mod;
            cnt=cnt%mod;
        }
        return cnt;
    }
};