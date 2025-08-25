class Solution {
public:
//RECURSIVE APPROCH
bool func(int ind,string &s,set<string>&st,vector<int>&dp){
    if(ind==s.size()){
        return true;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    string temp="";
    for(int j=ind;j<s.length();j++){
        temp+=s[j];
        if(st.find(temp)!=st.end()){
            if(func(j+1,s,st,dp)==true){
                return true;
            }
        }
    }
    return dp[ind]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        int n=s.length();
        vector<int>dp(n,-1);
        return func(0,s,st,dp);

    }
};