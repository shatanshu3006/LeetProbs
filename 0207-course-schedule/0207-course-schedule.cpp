class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //creating the adjacency matrix of the graph
        //to find who is connected to whom

        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        //creating indegree vecetor for all the nodes in the graph
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int it:adj[i]){
                inDegree[it]++;
            }
        }

        //queue that stores the one that we have detached and have to be stored
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        //topo vector so that we store in order of occurence
        vector<int>topo;
        while(!q.empty()){
            int f=q.front();
            
            q.pop();
            topo.push_back(f);

            for(auto it:adj[f]){
                inDegree[it]--; // deattaching the node
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        //if al the nodes have been traversed then the size of toopo vector wou;d be same as the nuber of nodes otherwise false
        return topo.size()==numCourses;
    }
};