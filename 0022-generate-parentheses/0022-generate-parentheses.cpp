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
void func( int open,int close,vector<string>&ans,string str){
    //perform a check
    // if(str.length()==2*n){
    //     // if(isValid(str)==true)ans.push_back(str);
    //     // return;

    // }
    if(open<0 || close<0)return;
    if(open==0 && close==0){
        ans.push_back(str);
        return;
    }
    // str+=')';
    // func(n,ans,str);
    // str.pop_back();
    // str+='(';
    // func(n,ans,str);
    // str.pop_back();

    if(open<=close)func(open-1,close,ans,str+'(');
    if(close>open)func(open,close-1,ans,str+')');
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        func(n,n,ans,str);
        return ans;
    }
};