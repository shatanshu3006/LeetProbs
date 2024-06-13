class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxlen=1,len=1,l=0,r=0,n=s.length();
        while(r<n-1){
            if((s[r]-'0')-(s[r+1]-'0')==-1){
                len++;
                maxlen=max(maxlen,len);
            }
            else{
                len=1;
            }
            r++;
        }
        return maxlen;
    }
};