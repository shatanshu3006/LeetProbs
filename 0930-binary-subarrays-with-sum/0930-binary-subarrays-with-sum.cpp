class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int j=0;
        map<int,int>mp;
        int sum=0;
        int count=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            if(sum==goal){
                count++;
            }
            if(mp[sum-goal]){
                count+=mp[sum-goal];
            }
            mp[sum]++;
            j++;
        }
        return count;
    }
};