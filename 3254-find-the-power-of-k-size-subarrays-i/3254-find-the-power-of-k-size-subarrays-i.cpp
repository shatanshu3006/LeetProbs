class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int r=k-1;
        int l=0;
        int n=nums.size();
        vector<int>ans;
        while(r<n){
            int cnt=0;
            for(int i=l;i<r;i++){
                if(nums[i+1]-nums[i]==1){
                    cnt++;
                }
                
            }
            if(cnt==k-1){
                ans.push_back(nums[r]);
            }
            else{
                ans.push_back(-1);
            }
            r++;
            l++;
        }
        return ans;
    }
};