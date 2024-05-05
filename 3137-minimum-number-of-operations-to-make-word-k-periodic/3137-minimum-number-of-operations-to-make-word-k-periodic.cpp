class Solution {
public:
// Calculate the frequency of each substring of length k that starts at an index that is divisible by k.
// The period of the final string will be the substring with the highest frequency.
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.length();
        int count=n/k;
        unordered_map<string,int>mp;

        for(int i=0;i<n;i+=k){
            mp[word.substr(i,k)]++;
        }
    int sub=INT_MIN;
        for(auto it:mp){
            sub=max(sub,it.second);
        }
        return count-sub;
        


    }
};