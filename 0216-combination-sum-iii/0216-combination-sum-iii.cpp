class Solution {
public:
void func(int ind,int k,int target,vector<int>&ds,vector<vector<int>>&ans){
    if(ds.size()==k && target==0){
    ans.push_back(ds);
    return;
    }
    if(ind>9 || target<0)return ;

    for(int i=ind;i<=9;i++){
        ds.push_back(i);
        func(i+1,k,target-i,ds,ans);
        ds.pop_back();
        // func(i+1,k,target,ds,ans);       dont need to call this since the loop will take all the other upcoming ones into ds
    }
    // if(ind>9){
    //     return;
    // }
    // if(target==0 && ds.size()==k){
    //     ans.push_back(ds);
    //     return;
    // }
    // ds.push_back(ind);
    // func(ind+1,k,target-ind,ds,ans);
    // ds.pop_back();
    // func(ind+1,k,target,ds,ans);
    // return;

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(1,k,n,ds,ans);
        return ans;
    }
};