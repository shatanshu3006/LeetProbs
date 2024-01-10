class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int ans=0;

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); //initial time when rotting begins
                    vis[i][j]=1;      //visited this point as it has rotten
                }
                else if(grid[i][j]==0){
                    vis[i][j]=1;      //visited the position and it is empty
                }
                else{
                    vis[i][j]=0;      //we have not yet come here
                }
            }
        }

        int diffRow[]={0,0,1,-1};
        int diffCol[]={1,-1,0,0};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            ans=max(ans,t);
            q.pop();

            for(int i=0;i<4;i++){
                int neighRow=r+diffRow[i];
                int neighCol=c+diffCol[i];

                if(neighRow>=0 && neighRow<n && neighCol>=0 && neighCol<m && vis[neighRow][neighCol]==0 && grid[neighRow][neighCol]==1){
                    q.push({{neighRow,neighCol},t+1});
                    //increment the time ans and push new coordinates
                    vis[neighRow][neighCol]=1;
                }
            }
        }

        //checking if all the points have been covered using the visited aray
        //if not then that has not rotten since we can reach there through traversal but if it is zero then it is not rotten at all 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    return -1;
                }
            }
        }
        return ans;
    }
};