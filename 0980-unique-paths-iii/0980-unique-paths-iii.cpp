class Solution {
public:int ans=0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int start_row,start_col,count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                }
                else if(grid[i][j]==1){
                    count++;
                    start_row=i;
                    start_col=j;
                }
                else if(grid[i][j]==2){
                    count++;
                }
            }
        }
        int i=start_row;int j=start_col;

        func(grid,i,j,count);
        return ans;
    }
    void func(vector<vector<int>>&grid,int row, int col,int count){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()){
            return ;
        }
        if(grid[row][col]==-1){
            return;
        }
        if(grid[row][col]==2 && count==1){
            ans++;
            return ;
        } 
        if(grid[row][col]==2 && count!=1){
            return ;
        }
//mark it as obstacle then you can't go there
        grid[row][col]=-1;

        func(grid,row-1,col,count-1);       //up
        func(grid,row+1,col,count-1);       //down
        func(grid,row,col-1,count-1);       //left
        func(grid,row,col+1,count-1);       //right

        grid[row][col]=1;       //backtracking
    }
};