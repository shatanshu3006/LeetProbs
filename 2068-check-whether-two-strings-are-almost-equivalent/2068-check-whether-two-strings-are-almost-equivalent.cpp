class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<word1.size();i++){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(abs(v1[i]-v2[i])>3){
                return false;
            }
        }
        return true;
    }
};