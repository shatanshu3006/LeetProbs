class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                st.push(it);
            }
            else{
                if(!st.empty()){
                    char temp=st.top();
                    if((it==')' && temp=='(') || (it==']' && temp=='[') || (it=='}' && temp=='{')){
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
};