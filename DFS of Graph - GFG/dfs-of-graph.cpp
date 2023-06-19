//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int node,vector<int>adj[],int vis[],vector<int>&ans){
        // the start root node is to be inserted into vis first
        vis[node]=1;
        // now pushing it into the ans from the start
        ans.push_back(node);
        //traverse all its neighbours
        for(auto it:adj[node]){
            // if the value is visited then it snoe to be taken into account
            // if not visited, then we call the dfs for that node till the last
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //making a visited array with 0 initialised
        int vis[V]={0};
        // start node is 0 
        int start=0;
        // ans vector to be returned
        vector<int>ans;
        
        dfs(start,adj,vis,ans);
        return ans;
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends