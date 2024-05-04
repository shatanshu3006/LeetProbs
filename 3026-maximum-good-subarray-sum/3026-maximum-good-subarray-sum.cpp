class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        vector<long long>pre(nums.size()+1);
        pre[0]=0;
        for(int i=1;i<=nums.size();i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int currele=nums[i];
            if(mp.find(currele-k)!=mp.end()){
                ans=max(ans,pre[i+1]-pre[mp[currele-k]]);
            }
            if(mp.find(currele+k)!=mp.end()){
                ans=max(ans,pre[i+1]-pre[mp[currele+k]]);
            }
            if(mp.find(currele)!=mp.end()){
                if(pre[i]-pre[mp[currele]]<=0){
                    mp[currele]=i;
                }
            }
            else{
                mp[currele]=i;
            }
        }
        if(ans==LLONG_MIN)return 0;
        return ans;
    }
};