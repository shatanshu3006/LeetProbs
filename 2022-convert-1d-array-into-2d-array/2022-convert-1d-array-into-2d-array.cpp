class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>mat(m,vector<int>(n));

        int sz=original.size();
        int cnt=0;
        if(m*n!=sz)return {};
        
        for( int i=0;i<sz;i++){
            mat[i/n][i%n]=original[i];
            
        }
        return mat;
    }
};