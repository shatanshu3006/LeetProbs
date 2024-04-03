class Solution {
public:
#include<vector>
//index represents the index of the word string
// int vis[7][7];
bool func(int i,int j,vector<vector<char>>&board,string word,int index,vector<vector<int>>&vis){
    int m=board.size();
    int n=board[0].size();

    if(index==word.size()){
        return true;
    }

    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    for(int k=0;k<4;k++){
        int nr=dr[k]+i;
        int nc=dc[k]+j;

        if(nr>=0 && nc>=0 && nr<m && nc<n){
            if(board[nr][nc]==word[index]){
                if(vis[nr][nc]==0){
                    //change the val to 1 and call the functin from THAT coordinate for the next index of the word
                    vis[nr][nc]=1;
                
                if(func(nr,nc,board,word,index+1,vis)){
                    return true;
                }
                //if that is also true then keep calling thr function 
                //reset once the traversal is done
                vis[nr][nc]=0;
                }
            }
        }

    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
            //mxn grid
            vector<vector<int>>vis(7,vector<int>(7,0));
        int m=board.size();
        int n=board[0].size();

        //memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(func(i,j,board,word,1,vis)){
                        return true;
                    }
                    //set it back to 0 
                    vis[i][j]=0;
                }
            }
        }
        return false;

    }
};