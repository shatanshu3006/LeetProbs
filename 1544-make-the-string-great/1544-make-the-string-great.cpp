class Solution {
public:
    string makeGood(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(ans.size() &&(abs(ans.back()-s[i])==32)){
                ans.pop_back();
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};