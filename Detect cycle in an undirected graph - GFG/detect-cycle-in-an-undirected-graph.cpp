//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detect(int src,vector<int>adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                // 3 came from 2 but 3 has 2 in its adjacency list
                // so if the adjacent node is not the parent, like 4 is not parent of 3
                //but 4 is adjacent node of 3, then we return true
                else if(parent!=adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // here we have multiple componenets so we have to deal with them first
        // later on if that detection gives us true then ther is a cycle if not then 
        // we move move our iteration further for other componenets
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends