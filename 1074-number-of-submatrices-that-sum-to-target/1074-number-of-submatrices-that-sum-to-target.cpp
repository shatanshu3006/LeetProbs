class Solution {
public:
int subarraySum(vector<int>&sum,int target){
    unordered_map<int,int>mp;
    mp[0]=1;
    int curr=0,ans=0;
    for(auto it:sum){
        curr+=it;
        if(mp.find(curr-target)!=mp.end()){
            ans+=mp[curr-target];
        }
        mp[curr]++;
    }
    return ans;
}
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            //vector storing the sum for this iteration
            vector<int>sum(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int k=0;k<matrix[0].size();k++){
                    sum[k]+=matrix[j][k];
                }
                ans+=subarraySum(sum,target);
            }
        }
        return ans;
    }
};