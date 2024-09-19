class Solution {
public:
bool isValid(string &str){
    stack<char>st;
        for(auto it:str){
            if(it=='('){
                st.push(it);
            }
            else{
                if(!st.empty()){
                    char temp=st.top();
                    if((it==')' && temp=='(')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
}
void func( int n,vector<string>&ans,string &str){
    //perform a check
    if(str.length()==2*n){
        if(isValid(str)==true)ans.push_back(str);
        return;
    }
    str+=')';
    func(n,ans,str);
    str.pop_back();
    str+='(';
    func(n,ans,str);
    str.pop_back();
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        func(n,ans,str);
        return ans;
    }
};