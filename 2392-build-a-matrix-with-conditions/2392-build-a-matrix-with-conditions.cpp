class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //approach by kahns algo
        vector<int>orderRows=toposort(rowConditions,k);
        vector<int>orderCols=toposort(colConditions,k);

        //if no topo sort exists
        if(orderRows.empty() || orderCols.empty()){
            return {};
        }

        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(orderRows[i]==orderCols[j]){
                    ans[i][j]=orderRows[i];
                }
            }
        }
        return ans;
    }
    //using kahns algo
    vector<int>toposort(vector<vector<int>>&graph,int k){
        //creating adjacency list
        vector<vector<int>>adj(k+1);
        vector<int>deg(k+1),order;

        for(auto it:graph){
            adj[it[0]].push_back(it[1]);
            deg[it[1]]++;       //indegree 
        }

        queue<int>q;
        //push allthe nodes with indegree 0 as they are the source and the come firs
        for(int i=1;i<=k;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            order.push_back(f);
            k--;
            for(auto it:adj[f]){
                deg[it]--;      //since the parent node is gone , its children will reduce their indegree by one , and the one that gets detached enters the queue for next of it's children as it might not be the last node hanging
                if(deg[it]==0){
                    q.push(it);
                }
            }
        }
        if(k!=0)return {};
        return order;
    }
};