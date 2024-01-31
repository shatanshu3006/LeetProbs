class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<double,int>mp;
        int n=nums.size();
        for(auto it:nums){
            mp[it]++;
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int ans=1;
        for(auto it:nums){
            if(mp[it]>=1){
                mp[it]--;

                double root=sqrt(it);
                int length=1;
                while(mp[root]>=2){
                    mp[root]-=2;
                    length+=2;

                    root=sqrt(root);

                }
                ans=max(ans,length);
            }
        }
        return ans;
    }
};