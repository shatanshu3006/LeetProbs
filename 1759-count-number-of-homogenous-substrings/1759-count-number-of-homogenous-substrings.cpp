class Solution {
public:
    int countHomogenous(string s) {
        const int mod=1e9+7;
        int l=0,r=0,n=s.size(),ans=0;
        while(r<n){
            while(s[l]!=s[r]){
                l++;
            }
            if(s[l]==s[r]){
                ans=(ans+(r-l+1))%mod;
            }
            r++;
        }
        return ans;
    }
};