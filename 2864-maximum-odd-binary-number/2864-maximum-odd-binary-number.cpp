class Solution {
public:
//create the largest number first and just lave one at the end t be attached to make it odd
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        int zeroes=n-ones;
        string ans="";
        for(int i=0;i<ones-1;i++){
            ans+='1';
        }
        for(int i=0;i<zeroes;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};