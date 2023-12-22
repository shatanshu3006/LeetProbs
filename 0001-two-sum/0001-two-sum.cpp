class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int v=target-nums[i];
            if(mp.count(v)>0){
                ans.push_back(i);
                ans.push_back(mp[v]);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};