class Solution {
public:
int func(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    int n=grid.size();
    int m=grid[0].size();

    if(j1<0 || j2<0 || j1>=m || j2>=m){
        return -1e8;
    }

    //if we reach the last row,2 cases arise either they are on the same block or diff
    if(i==n-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    //now there are 3x3 possibilities for both i,j together

    int maxi=-1e8;
    for(int delta_j1=-1;delta_j1<=1;delta_j1++){
        for(int delta_j2=-1;delta_j2<=1;delta_j2++){
            int value=0;
            if(j1==j2){
                value=grid[i][j1];
            }
            else{
                value=grid[i][j1]+grid[i][j2];
            }
            value+=func(i+1,j1+delta_j1,j2+delta_j2,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        //since all the movements are focused downwards, there are 3 parameters, i,j1,j2
        //3d dp required

        int n=grid.size();
        int m=grid[0].size();

        //robo1 starts from top left
        //robo2 starts from top right

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,grid,dp);
    }
};