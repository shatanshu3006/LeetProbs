class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        vector<int> ind(n,0);
        for(auto it:richer)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(ind[i] == 0)
            q.push(i);
            ans[i]=i;
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(quiet[node]<quiet[it])
                {
                    quiet[it]=quiet[node];
                    ans[it]=ans[node];
                }
                ind[it]--;
                if(ind[it] == 0)
                q.push(it);
            }
        }
        return ans;
    }
};