class Solution {
public:
int mod=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        map<int,int>mp;
        vector<int>v=nums;
        sort(v.begin(),v.end());
        if(v[v.size()-1]==0)return 0;
        long long ans=1;
        bool check=false;
        for(int i=0;i<nums.size();i++){
            if(mp.find(1)!=mp.end() && check==true && nums[i]==1){
                ans=ans%mod;
                ans=ans*(i-mp[1])%mod;
            }
            if(nums[i]==1){
                mp[1]=i;
                check=true;
            }
        }
        return ans;
    }
};