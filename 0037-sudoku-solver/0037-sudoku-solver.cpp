/*

    Time Complexity : O(9^(N*N)) : For every unassigned index there are 9 possible options so the worst-case time
    complexity of sudoku solver is O(9^(N*N)).

    Space Complexity : O(1), Constant space.

    Solved using Matrix + Backtracking.

*/

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){        //found in row
                return false;
            }
            if(board[row][i] == ch){        //found in column
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){      //found in 3x3 sub-matrix.
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){                  //traverse the row
            for(int j=0; j<board[0].size(); j++){           //traverse the columns
                if(board[i][j] == '.'){                     //check for the empty spots
                    for(char ch='1'; ch<='9'; ch++){        //traverse filling the characters
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';              //backtrack if found false.
                        }
                    }
                    return false;
                }
            }
        }
        return true;                    //return true if everything is filled already / has been filled.
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};