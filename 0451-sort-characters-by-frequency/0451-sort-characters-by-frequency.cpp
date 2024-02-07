class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(auto it:s){
            mp[it]++;
        }
        //using priority queue to store the max freq element at the top
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int n=pq.top().first;
            while(n--){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};