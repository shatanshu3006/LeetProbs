class Solution {
public:
    bool isSafe(int row , int col , vector<vector<int>> &board , int n){
    //check for same row
     //storing the values.

    int x = row;
    int y = col;
    
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }
    
     //not checking for the columns as the queen is added in column
        //check for diagonals 
        // checking for the NW diagonal

    x = row;
    y = col;
    
    while(x>=0 && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x--;
    }
    
     //check for another diagonal (SW)
    x = row;
    y = col;
    
    while(x<n && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    // no need to check for NE and SE diagonals as queen hasn'e been added to the right yet.

        // if all above condition get passed then we can place the queen there.

    return true;
}

    void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n , int &count){
    //base case
    if(col == n){
        count++;
        return ;
    }
    
     // solving only for 1 column rest will be completed by recursion

    for(int row = 0 ; row < n ; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;
            solve(col+1 , ans , board , n , count);
            //backtrack
            board[row][col] = 0;
        }
    }
}

    int totalNQueens(int n) {
        vector<vector<int>> board(n , vector<int>(n,0));
        vector<vector<int>> ans;
        int count = 0;
        
        solve(0 , ans , board , n , count);
        return count;
    }
};