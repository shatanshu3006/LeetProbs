class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
    int n=grid.size(),m=grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]==1){
        return 0;
    }
    vis[i][j]=1;
    int left=func(i,j-1,grid,vis);
    int right=func(i,j+1,grid,vis);
    int down=func(i+1,j,grid,vis);
    int up=func(i-1,j,grid,vis);

    vis[i][j]=0;

    return max({up,left,right,down})+grid[i][j];
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                vector<vector<int>>vis(n,vector<int>(m,0));
                ans=max(ans,func(i,j,grid,vis));
            }
        }
        return ans;
    }
};