class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
      for(auto i:s){
        if(i=='(' || i=='{' || i=='[') 
          st.push(i);
        else{
          if(!st.empty()){
            char temp=st.top();
            if( (i==')'&&temp=='(') || (i==']'&&temp=='[') || (i=='}'&&temp=='{') )
              st.pop();
            else return false;
          }
          else return false;
        }
      }
      if(!st.empty())
          return false;
        else
          return true;
    }
};