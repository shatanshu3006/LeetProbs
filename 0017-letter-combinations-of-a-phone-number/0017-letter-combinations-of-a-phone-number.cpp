class Solution {
public:
void func(int ind,int n,string &digits,vector<string>&dict,vector<string>&ans,string combo){
    if(ind==n){
        ans.push_back(combo);
        return;
    }
    string val=dict[digits[ind]-'0'];   //to convert digits[ind] to real numbers
    for(int i=0;i<val.length();i++){
        combo+=val[i];
        func(ind+1,n,digits,dict,ans,combo);
        combo.pop_back();       //backtrack
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.size();
        vector<string>dict={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(n==0){
            return ans;
        }
        func(0,n,digits,dict,ans,"");
        return ans;
    }
};