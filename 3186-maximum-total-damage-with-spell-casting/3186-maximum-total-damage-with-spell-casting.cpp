class Solution {
public:
long long func(vector<pair<int,long long>>&vp,int index,vector<long long>&dp){
    if(index>=vp.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    long long not_take=func(vp,index+1,dp);

    int nextIndex=index+1;

    while(nextIndex<vp.size() && vp[index].first+3>vp[nextIndex].first){
        nextIndex++;
    }
    long long take=(long long)vp[index].first*vp[index].second + func(vp,nextIndex,dp);

    return dp[index]=max(take,not_take);
}
    long long maximumTotalDamage(vector<int>& power) {
        map<int,long long>mp;
        for(auto it:power){
            mp[it]++;
        }
        vector<pair<int,long long>>vp;
        for(auto it:mp){
            vp.push_back(it);
        }
        vector<long long >dp(power.size(),-1);
        return func(vp,0,dp);
    }
};