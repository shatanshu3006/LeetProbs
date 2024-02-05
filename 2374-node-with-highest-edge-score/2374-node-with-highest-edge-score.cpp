class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]].push_back(i);
        }
        //we use node variable for pointing to the ans with the maximum edge_score
        int node=-1;int maxi=-1;
        for(auto it:mp){
            long long edge_score=0;
            for(auto p:it.second){
                edge_score+=p;
            }
            if(maxi<edge_score){
                maxi=edge_score;
                node=it.first;
            }
        }
        return node;
    }
};