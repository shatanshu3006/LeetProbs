class Solution {
public:
void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    if(row<0 || row>=n || col<0 || col>=m || grid[row][col]=='0' || vis[row][col]==1){
        return;
    }
    vis[row][col]=1;
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    for(auto ele:dir){
        int new_row=row+ele.first;
        int new_col=col+ele.second;

        dfs(new_row,new_col,grid,vis);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};