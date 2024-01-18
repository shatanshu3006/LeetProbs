class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        map<int,int>mp1;
        for(auto it:mp){
            mp1[it.second]++;
        }
        return mp1.size()==mp.size();
        
    }
};