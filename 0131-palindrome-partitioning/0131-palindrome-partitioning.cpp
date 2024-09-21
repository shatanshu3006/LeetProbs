class Solution {
public:
// using the stl s.substr(index,i-index+1) for storing all the substrings after checking if the string is a palindrome or not 
// runniing hte function again and then popping abck for backtracking
bool isValid(string s,int index,int i){
    while(index<=i){
        if(s[index]!=s[i]){
            return false;
        }
        index++;
        i--;
    }
    return true;
}
void f(vector<vector<string>>&ans, vector<string>&ds,string &s,int index){
        if(index==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(isValid(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                f(ans,ds,s,i+1);
                ds.pop_back();
            }
        }
}
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>>ans;
        vector<string> ds;
        f(ans,ds,s,0);
        return ans;
    }
};