class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int n=grid.size();
        for(int i=1;i<=n*n;i++){
            mp[i]=0;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int rep,nonrep;
        for(auto it:mp){
            if(it.second==2){
                rep=(it.first);
            }
            if(it.second==0){
                nonrep=(it.first);
            }
        }
        ans.push_back(rep);
        ans.push_back(nonrep);
        return ans;
    }
};