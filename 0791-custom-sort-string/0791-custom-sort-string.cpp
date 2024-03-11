class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:order){
            if(mp.find(it)!=mp.end()){
                if(mp.find(it) != mp.end())
                ans.append(mp[it], it);
                mp.erase(it);
            }
        }
        for(auto it:mp){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};