class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return n;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=1;
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(st.find(val-1)==st.end()){
                int count=0;
                while(st.find(val)!=st.end()){
                    count++;
                    val++;
                }
                ans=max(ans,count);
            }
        }
        return ans;

    }
};