class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        int l=0,r=0,maxlen=1,count=1;
        while(r<n-1){
            if(s[r]==s[r+1]){
                count++;
                maxlen=max(maxlen,count);
            }
            else{
                count=1;
            }
            r++;
        }
        return maxlen;
    }
};