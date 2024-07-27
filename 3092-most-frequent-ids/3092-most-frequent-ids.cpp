class Solution {
public:
typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        priority_queue<pair<ll ,int>>pq;
        map<int,ll>mp;
        vector<ll>ans(n,0);
        for(int i=0;i<n;i++){
            mp[nums[i]]+=freq[i];
            pq.push({mp[nums[i]],nums[i]});
            while(pq.top().first!=mp[pq.top().second]){
                pq.pop();
            }
            ans[i]=pq.top().first;
        }
        return ans;
    }
};