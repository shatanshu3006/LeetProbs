class Solution {
public:
//First, we will run a loop(say row) from 1 to n.
// Inside the loop, we will call a generateRow() function and add the returned list to our final answer. Inside the function we will do the following:
// First, we will store the 1st element i.e. 1 manually.
// After that, we will use a loop(say col) that runs from 1 to n-1. It will store the rest of the elements.
// Inside the loop, we will use the specified formula to print the element. We will multiply the previous answer by (row-col) and then divide it by col itself.
// Thus, the entire row will be stored and returned.
// Finally, we will return the answer list.

void func(vector<int>&temp,int row){
    long long ans=1;
    temp.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        temp.push_back(ans);
    }
    return;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            func(temp,i);
            ans.push_back(temp);
        }
        return ans;
    }
};