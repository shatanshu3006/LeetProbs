//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[9][9],int row,int col,int number){
        for(int a=0;a<9;a++){
            if(grid[a][col]==number){   //column check
                return false;
            }
            if(grid[row][a]==number){       //row check
                return false;
            }
            if(grid[3*(row/3)+a/3][3*(col/3)+a%3]==number){   //3x3 submatrix check
                return false;
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[9][9])  
    { 
        // Your code here
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]==0){
                    for(int number=1;number<=9;number++){
                        if(isValid(grid,i,j,number)==true){
                            grid[i][j]=number;
                            //driver recursion call
                            if(SolveSudoku(grid)==true){
                                return true;
                            }
                            else{
                                //backtracking
                                grid[i][j]=0;
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        if(SolveSudoku(grid)==true)
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends