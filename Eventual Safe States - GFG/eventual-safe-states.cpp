//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfsCheck(int node,vector<int>adj[],int vis[],int vispath[],int check[]){
        vis[node]=1;
        vispath[node]=1;
        //we have not yet confirmed if it is safe so check is zero for that node
        check[node]=0;
        
        //traverse for adjacent nodes
        for(auto it:adj[node]){
            //when the node is not visited
            if(vis[it]==0){
                if(dfsCheck(it,adj,vis,vispath,check)==true){
                    //if it has some other path then it canot be in check
                    check[node]=0;
                    return true;
                }
            }
            //if the node has been previously visited
            else if(vispath[it]==1){
                check[node]=0;
                return true;
            }
        }
        //if the node is not in a cycle and is in path then we can use it in check
        check[node]=1;
        vispath[node]=0; //emptying the array again for backtracking
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        //A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
        //visiting array
        int vis[v]={0};
        int vispath[v]={0};
        //maintaining check to confirm that node to be in ans or not
        int check[v]={0};
        vector<int>safeNodes;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                dfsCheck(i,adj,vis,vispath,check);
            }
        }
        for(int i=0;i<v;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends