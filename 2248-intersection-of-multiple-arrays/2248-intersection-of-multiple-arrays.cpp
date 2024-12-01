class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
      for(auto it:nums)
      {
        for(auto i:it)
        {
            mp[i]++;
        }
      }
      int n= nums.size();
      vector<int>ans;
      for(auto it:mp)
      {
        if(it.second==n)
        {
            ans.push_back(it.first);
        }
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
    
};