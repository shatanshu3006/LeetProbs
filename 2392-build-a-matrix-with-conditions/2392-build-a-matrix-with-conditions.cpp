class Solution {
public:
//topo sort for both rows and cols
// acyclic DAG for both rows and cols will be needed to be checked while topo sort
//if any one of them turn out to be cyclic we return empty matrix
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int,vector<int>>graph;
        for(auto it:rowConditions){
            graph[it[0]].push_back(it[1]);
        }
    // we topo sort the graph according to who came first
    // there may be many sorts we take any one
        vector<int>row_sorting=topo_sort(graph,k);
        graph.clear(); //done woth row sorting

        for(auto it:colConditions){
            graph[it[0]].push_back(it[1]);
        }
        vector<int>col_sorting=topo_sort(graph,k);

//if DAG not found after topo sort we return empty vectors 
        if(row_sorting.empty() || col_sorting.empty()){
            return {};
        }
//build the matrix using row_sorting and col-sorting
// pair<int,int> is important to keep the position of the indices
        unordered_map<int,pair<int,int>>val_position;
        for(int i=0;i<k;i++){
            val_position[row_sorting[i]].first=i;
            val_position[col_sorting[i]].second=i;
        }
        vector<vector<int>>ans(k,vector<int>(k,0));

//since the numbers of matrix except zero are from 1 to k
        for(int number=1;number<=k;number++){
            int row=val_position[number].first;
            int col=val_position[number].second;
            ans[row][col]=number;
        }

        return ans;

    }

    vector<int>topo_sort(unordered_map<int,vector<int>>&graph,int k){
        unordered_set<int>vis;
        unordered_set<int>curr_path;

        vector<int>res;

        for(int src=1;src<=k;src++){
            //if we find a cyclic graph
            if(!dfs(src,graph,vis,curr_path,res)){
                return {};
            }
        }


         // we will have res as reversed so we need to reverse it one more time
        reverse(res.begin(),res.end());
        return res;
    }

    bool dfs(int src,unordered_map<int,vector<int>>&graph,unordered_set<int>&vis,unordered_set<int>&curr_path,vector<int>&res){
        if(curr_path.count(src))return false;   //cycle detected as we arrive source
        if(vis.count(src))return true;         // already visited

        vis.insert(src);
        curr_path.insert(src);

        for(int it:graph[src]){
            if(!dfs(it,graph,vis,curr_path,res)){       //if any child returns false
                return false;
            }
        }

        curr_path.erase(src);   //backtrack path
        res.push_back(src);
        return true;
    }
};