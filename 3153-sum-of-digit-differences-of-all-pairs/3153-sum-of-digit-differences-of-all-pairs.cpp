class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string>numString;
        for(auto it:nums){
            numString.push_back(to_string(it));
        }

        long long res=0;
        for(int i=0;i<numString[0].size();i++){
            vector<int>cnt(10,0);
            for(auto s:numString){
                cnt[s[i]-'0']++;
            }
            for(int j=0;j<=9;j++){
                for(int k=j+1;k<=9;k++){
                    res+=(cnt[j]*cnt[k]);
                }
            }
        }
        return res;
    }
};