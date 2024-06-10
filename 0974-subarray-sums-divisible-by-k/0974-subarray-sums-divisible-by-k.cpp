class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>prefix_map={{0,1}};
        int n=nums.size();
        int sum=0,ans=0;
        int right=0;
        while(right<n){
            sum=(sum+nums[right])%k;
            if(sum<0){
                sum+=k;
            }
            if(prefix_map.find(sum)!=prefix_map.end()){
                ans+=prefix_map[sum];
                prefix_map[sum]++;
            }
            else{
                prefix_map[sum]=1;
            }
            right++;
        } 
        return ans;
    }
};