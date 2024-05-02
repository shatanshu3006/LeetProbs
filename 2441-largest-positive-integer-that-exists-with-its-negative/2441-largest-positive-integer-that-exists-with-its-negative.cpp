class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            auto f=it.first;
            if(mp.find((-1)*f)!=mp.end()){
                ans=max(ans,abs(f));
            }
        }
        return ans;
    }
};