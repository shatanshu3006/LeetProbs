class Solution {
public:
    int strStr(string haystack, string needle) {
        //solved using a find function , can be done using KMP algorithm too.
        int ans= haystack.find(needle);
        if(ans<0 || ans>haystack.length()){
            return -1;
        }
        else{
            return ans;
        }
    }
};