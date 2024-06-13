class Solution {
public:
    bool checkOnesSegment(string s) {
        int l=0,r=s.size()-1;
        // Two pointers, left at starting, and right at ending of String.

         while(s[l] == '0'){
            l++; //Increase left to Ignore all leading zeros of String
        }
        while(s[r] == '0'){
            r--; //Decrease right to Ignore all trailing zeros of String
        }
        while(l<=r){ //checking for only the remaing portion of String
            if(s[l] == '0') //If zero present, then partition is created, hence, more than one group of 1's
                return false; //hence, false
            l++;
        }
        return true; //else, true
    }
};