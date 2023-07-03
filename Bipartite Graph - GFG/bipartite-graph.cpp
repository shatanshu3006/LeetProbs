//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    //eliminating the component cases
    bool check(int start,int V,vector<int>adj[],int color[]){
        queue<int>q;
	    q.push(start);
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        for(auto it:adj[node]){
	            //if the adjacent node is yet not colored
	            //we assign the opposite color of the node
	            if(color[it]==-1){
	                color[it]=!color[node];
	                q.push(it);
	            }
	            
	            // is the adjacent node has already a color
	            // if some one has already colored we checkthe polarity of the color
	            // for odd cyclic they are not bipartite
	            //for even cyclic they are bipartite
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    //writing for components in case they are there
	    // we traverse over them and using a check function we confirm if the other adjacent node 
	    //has been visited with same color or not
	    // if check returns false then its over
	    //else true
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends