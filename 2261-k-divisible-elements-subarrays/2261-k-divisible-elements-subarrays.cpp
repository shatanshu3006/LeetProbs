class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            vector<int>tt;
            int ct=0;
            for(int j=i;j<n;j++)
            {
                tt.push_back(nums[j]);
                if(nums[j]%p==0)
                    ++ct;
                if(ct>k)
                    break;
                ans.insert(tt);
                    
            }
        }
        return ans.size();
    }
};