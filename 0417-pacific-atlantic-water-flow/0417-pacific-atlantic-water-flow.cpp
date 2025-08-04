class Solution {
public:

//basically check the visited1 for the cells that can reach only atlantic
//for visited2, it is pacific , then we return the ones that are common among the two 


int dr[5] = { 0, 0, -1, 1 };
int dc[5] = { 1, -1, 0, 0 };

bool safe(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }
    return false;
}

void bfs(vector<vector<int>>&heights,int n,int m,queue<pair<int,int>>q,vector<vector<bool>>&visited){
    while(!q.empty()){
        pair<int,int>front=q.front();
        q.pop();
        int x=front.first;
        int y=front.second;

        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nr=x+dr[i];
            int nc=y+dc[i];

            if(safe(nr,nc,n,m)==true && heights[x][y]<=heights[nr][nc]){
                if(visited[nr][nc]==false){
                    q.push({nr,nc});

                    visited[nr][nc]=true;
                }
            }
        }

    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        queue<pair<int,int>>q1,q2;

        vector<vector<int>>ans;

        //stores the visited coordinates for the first traverssal and second traversal
        vector<vector<bool>>visited1(n,vector<bool>(m,false));
        vector<vector<bool>>visited2(n,vector<bool>(m,false));

        for(int j=0;j<m;j++){
            q1.push({0,j});
            q2.push({n-1,j});
        }

        for(int i=1;i<n;i++){
            q1.push({i,0});
            q2.push({i-1,m-1});
        }

        //bfs for the first ocean
        bfs(heights,n,m,q1,visited1);

        //bfs for the second ocean
        bfs(heights,n,m,q2,visited2);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited1[i][j]==true && visited2[i][j]==true){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }

        return ans;


    }
};