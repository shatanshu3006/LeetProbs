class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        int cnt=0;int n=nums.size(),m=q.size();
        vector<int>occ(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                cnt++;
                occ[cnt-1]=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            if(q[i]>cnt){
                ans.push_back(-1);
            }
            else{
                ans.push_back(occ[q[i]-1]);
            }
        }
        return ans;
    }
};