class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        
        int n=nums.size();
        set<vector<int>>bigset;
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i+1;j<n;j++){
                int third=-(nums[i]+nums[j]);

                if(st.find(third)!=st.end()){
                    vector<int>temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    bigset.insert(temp);
                }
                st.insert(nums[j]);
            }
            
        }
        for(auto it:bigset){
            ans.push_back(it);
        }
        return ans;
    }
};