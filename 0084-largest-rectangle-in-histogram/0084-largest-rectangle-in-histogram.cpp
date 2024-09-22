class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        int n=h.size();
        int maxa=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[st.top()]>h[i])){
                int height=h[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                maxa=max(maxa,height*width);
            }
            st.push(i);
        }
        return maxa;
    }
};