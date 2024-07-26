class Solution {
public:
    int numSub(string s) {
        const int mod=1e9+7;
        //this is for single length subarrays
        //long long totalSum=count(s.begin(),s.end(),'1');
        long long totalSum=0;
        int l=0,n=s.size();
        while(l<n){
            if(s[l]=='0'){
                l++;
            }
            else{
                int r=l+1;
                long long countGaps=1;
                while(s[l]==s[r] && r<n){
                    countGaps++;
                    r++;

                }
                l=r;
                totalSum+=countGaps*(countGaps+1)/2;
            }
        }
        return totalSum%mod;
    }
};