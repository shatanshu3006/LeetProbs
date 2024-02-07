class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //first row,first col,last row,last,col

                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        //for the 4 neighbours we use a diff array
        int diffrow[]={-1,0,+1,0};
        int diffcol[]={0,+1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_row=row+diffrow[i];
                int new_col=col+diffcol[i];

                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && grid[new_row][new_col]==1 && vis[new_row][new_col]==0){
                    q.push({new_row,new_col});
                    vis[new_row][new_col]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};