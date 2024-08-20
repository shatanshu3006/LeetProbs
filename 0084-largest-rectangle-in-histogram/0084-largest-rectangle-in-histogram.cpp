class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_area=0;
        stack<int>st;
        //declaring the leftsmall array for all the elements and rightsmall array
        int leftSmall[n];
        int rightSmall[n];

        //making the leftSmall array
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                leftSmall[i]=0;
            }
            else{
                leftSmall[i]=st.top()+1;
            }
            st.push(i);
        }

        //clearing the stack to be reused
        while(!st.empty()){
            st.pop();
        }

        //making the rightSmall array
        //traversing in the reverse but doing the same operations
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                rightSmall[i]=n-1;
            }
            else{
                rightSmall[i]=st.top()-1;
            }
            st.push(i);
        }
        //iterating again for the max area
        for(int i=0;i<n;i++){
            max_area=max(max_area,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return max_area;

    }
};