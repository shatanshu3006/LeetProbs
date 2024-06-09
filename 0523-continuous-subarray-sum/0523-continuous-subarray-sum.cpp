class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=1,sum=0;
        map<int,int>mp;
        mp[0]=1;
        while(right<n){
            sum+=nums[right];
            int rem=sum-k;
            //if the rem exists in the array then till that index the sum exists
            //if the sum exists then return true
            //check que 560
            if(mp.find(rem)!=mp.end()){
                return true;
            }
            else{
            mp[sum]++;
            }
            right++;
        }
        return false;
    }
};