class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();

        // Transposing the matrix
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                swap(matrix[i][j], matrix[j][i]);

        // Reversing each row of the matrix
        for (int k = 0; k < n; k++) 
            reverse(matrix[k].begin(), matrix[k].end());
    }

    // tooooo good , check for the solution (4k upvotes)!!
};

//doubt : how about 
//      for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//       matrix[i][j]=matrix[n-j][i];
//    }
// }