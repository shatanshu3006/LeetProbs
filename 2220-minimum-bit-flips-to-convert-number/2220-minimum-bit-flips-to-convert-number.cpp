class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32>startbit(start),goalbit(goal);
        int ans=0;
        for(int i=0;i<32;i++){
            if(startbit[i]!=goalbit[i])ans++;
        }
        return ans;
    }
};