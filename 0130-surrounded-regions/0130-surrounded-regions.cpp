class Solution {
public:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

void dfs(int row, int col, vector<int>&r, vector<int>&c, vector<vector<int>>&visited,vector<vector<char>>&board){
    visited[row][col]=1;
    int n=board.size();
    int m=board[0].size();
int i=0;

do{
        int nrow=row+r[i];      //neighboring row
        int ncol=col+c[i];         //neighboring col 

        //base/ edge cases
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,r,c,visited,board);
        }
        i++;
}
while(i<4);

    // while(i<4){
    //     int nrow=row+r[i];
    //     int ncol=col+c[i];

    //     //base/ edge cases
    //     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
    //         dfs(nrow,ncol,r,c,visited,board);
    //     }
    //     i++;
    // }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m=board[0].size();

        //using a visited vector for all the cells t be marked
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int> r={1,0,-1,0};
        vector<int>c={0,1,0,-1};

        for(int i=0;i<n;i++){       //traversers for every row
            //not visited
            if(board[i][0]=='O' && visited[i][0]==0){
                dfs(i,0,r,c,visited,board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                //for "0". and not visited c
                dfs(i,m-1,r,c,visited,board);
            }
        }

        for(int j=0;j<m;j++){
            // O and not visited
            if(board[0][j]=='O' && visited[0][j]==0){
                dfs(0,j,r,c,visited,board);
            }
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                dfs(n-1,j,r,c,visited,board);
            }
        }

        for(int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};