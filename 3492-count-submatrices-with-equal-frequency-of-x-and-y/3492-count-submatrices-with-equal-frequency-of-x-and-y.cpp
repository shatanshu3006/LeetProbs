class Solution {
public:
vector<vector<int>>calculatePrefixSum(vector<vector<char>>&grid,char target){
    int rows=grid.size(),cols=grid[0].size();

    vector<vector<int>>prefixSum(rows,vector<int>(cols,0));

//2d prefix sum 
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            prefixSum[row][col]=(grid[row][col]==target);
            if(row>0)prefixSum[row][col]+=prefixSum[row-1][col];
            if(col>0)prefixSum[row][col]+=prefixSum[row][col-1];

            if(row>0 && col>0)prefixSum[row][col]-=prefixSum[row-1][col-1];
        }
    }
    return prefixSum;
}
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows=grid.size(),cols=grid[0].size();

        vector<vector<int>>xCountPrefixSum=calculatePrefixSum(grid,'X');
        vector<vector<int>>yCountPrefixSum=calculatePrefixSum(grid,'Y');

        int matchingSubmatricesCount=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(xCountPrefixSum[row][col]==yCountPrefixSum[row][col] && xCountPrefixSum[row][col]>0){
                    matchingSubmatricesCount++;
                }
            }
        }
        return matchingSubmatricesCount;
    }
};