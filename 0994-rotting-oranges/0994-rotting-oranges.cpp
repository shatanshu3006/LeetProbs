class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int time=0;
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int curr_time=node.second;
            time=max(time,curr_time);
            int x=node.first.first;
            int y=node.first.second;
            //up
            if(x>=1){
            if(mat[x-1][y]==1 && vis[x-1][y]==0){
                vis[x-1][y]=2;
                q.push({{x-1,y},curr_time+1});
                //time=max(time,curr_time+1);
            }
            }
            //left
            if(y>=1){
            if(mat[x][y-1]==1 && vis[x][y-1]==0){
                vis[x][y-1]=2;
                q.push({{x,y-1},curr_time+1});
                //time=max(time,curr_time+1);
            }
            }
            
            //right
            if(y<=m-2){
            if(mat[x][y+1]==1 && vis[x][y+1]==0){
                vis[x][y+1]=2;
                q.push({{x,y+1},curr_time+1});
                //time=max(time,curr_time+1);
            }
            }
            //down
            if(x<=n-2){
            if(mat[x+1][y]==1 && vis[x+1][y]==0){
                vis[x+1][y]=2;
                q.push({{x+1,y},curr_time+1});
               // time=max(time,curr_time+1);
            }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return time;
    }
};