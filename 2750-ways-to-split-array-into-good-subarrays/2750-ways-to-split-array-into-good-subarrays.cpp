class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int lastone=-1;
        int mod=1e9+7;
        long long ans=1;int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(lastone!=-1){
                    ans=(ans*(i-lastone))%(mod);
                }
                lastone=i;
            }
        }
        if(lastone==-1)return 0;
        return ans;
    }
};