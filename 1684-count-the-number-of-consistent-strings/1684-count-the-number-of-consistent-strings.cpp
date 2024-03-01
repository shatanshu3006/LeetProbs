class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        for(auto it:allowed){
            mp[it]++;
        }
        int n=words.size(),ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<words[i].length();j++){
                if(mp.find(words[i][j])!=mp.end()){
                    cnt++;
                }
            }
            if(cnt==words[i].length()){
                ans++;
            }
        }
        return ans;
    }
};