class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        // inserted every number from nums into hashset
        int n;
        n=nums.size();
        vector<int> ans(n-s.size());
        for(int i=1,j=0;i<=n;i++){
            if(s.count(i)!=1){
                ans[j++]=i;//adding all the elements not found in the hashset
            }
        }
        return ans;
        
    }
};