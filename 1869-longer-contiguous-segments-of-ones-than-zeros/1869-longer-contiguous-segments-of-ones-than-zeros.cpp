class Solution {
public:
    int max_contiguous_segment(string s,char ch){
        int l=0,r=0,n=s.length(),maxlen=0;
        while(r<n){
            if(s[r]!=ch){   //found another character so this substring is over
                l=r+1;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
    bool checkZeroOnes(string s) {
        if(max_contiguous_segment(s,'1')>max_contiguous_segment(s,'0')){
            return true;
        }
        else{
            return false;
        }
    }
};