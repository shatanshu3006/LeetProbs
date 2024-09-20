class Solution {
public:
void solve(int ind,int n,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans){
    if(ind==n){
        ans.push_back(subset);
        return;
    }

    //pick the current element
    subset.push_back(nums[ind]);
    solve(ind+1,n,nums,subset,ans);

    //do not pick the current element
    subset.pop_back();
    solve(ind+1,n,nums,subset,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>subset;
        vector<vector<int>>ans;
        solve(0,n,nums,subset,ans);
        return ans;
    }
};