class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),r=0,l=0,maxlen=0;
        vector<int>hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){//we have already encountered the element so pull l to max[r]+1
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;// now we have a new l for the unique elements and we can proceed with r further
            }

            }
            //update the ans
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};