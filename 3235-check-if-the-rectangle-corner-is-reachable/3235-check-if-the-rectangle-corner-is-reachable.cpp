class Solution {
public:
//Only cases where answer is not possible is when path from lower left corner to upper right corner is blocked. There are 4 cases where it is possible :

// Sequence of circles connect lower edge to left edge of rectangle
// Sequence of circles connect lower edge to upper edge of rectangle
// Sequence of circles connect right edge to left edge of rectangle
// Sequence of circles connect right edge to upper edge of rectangle

// create a graph out of circles, where two circles have edge between them if they are touching and intersecting. Then simply run a bfs from circles touching lower edge and right edge to see if we can reach upper or left edge. If we can reach, then there is no path, else there is a path.


    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
       int n=circles.size();
        vector<vector<int>> graph(n);
        set<int> bottom,right,left,up;
        //create graph of circles
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(1LL*(circles[i][2]+circles[j][2])*(circles[i][2]+circles[j][2])>=
                  1LL*(circles[i][0]-circles[j][0])*(circles[i][0]-circles[j][0])+1LL*(circles[i][1]-circles[j][1])*(circles[i][1]-circles[j][1])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
            if(circles[i][0]<=circles[i][2]){
                bottom.insert(i);
            }
            if(circles[i][1]<=circles[i][2]){
                left.insert(i);
            }
            if(X-circles[i][0]<=circles[i][2]){
                up.insert(i);
            }
            if(Y-circles[i][1]<=circles[i][2]){
                right.insert(i);
            }
        }

        //run bfs from circles touching 
        //lower and right edges
        bool pos=true;
        queue<int> q;
        vector<int> vis(n,0);
        for(auto& b:bottom){
            q.push(b);
            vis[b]=1;
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            if(up.contains(node) || left.contains(node)){
                pos=false;
                break;
            }
            for(auto& g:graph[node]){
                if(!vis[g]){
                    vis[g]=1;
                    q.push(g);
                }
            }
        }
        if(!pos) return false;
        for(int i=0;i<n;++i) vis[i]=0;
        for(auto& r:right){
            q.push(r);
            vis[r]=1;
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            if(up.contains(node) || left.contains(node)){
                pos=false;
                break;
            }
            for(auto& g:graph[node]){
                if(!vis[g]){
                    vis[g]=1;
                    q.push(g);
                }
            }
        }
        return pos;
    }
};