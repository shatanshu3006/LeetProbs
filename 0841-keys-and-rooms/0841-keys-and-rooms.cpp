class Solution {
public:
void dfs(vector<vector<int>>&rooms,int node,vector<bool>&visited){
    if(visited[node]==true){
        return;
    }
    visited[node]=true;

    for(auto it:rooms[node]){
        dfs(rooms,it,visited);
    }
    
}
//there is no constraint on visting the room in order
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //DFS APPROACH
        int n=rooms.size();
        vector<bool>visited(n,false);
//this can be done without making an adjacency list too as rooms vector itself acts as 
//an adjacency list
//starting the dfs with the starting node in rooms
        dfs(rooms,0,visited);
        for(auto it:visited){
            if(it==false){
                return false;
            }
        }
        return true;
    }
};