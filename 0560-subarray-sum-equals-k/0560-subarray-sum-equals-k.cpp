class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int j=0;int ans=0;int sum=0;int n=nums.size();
        while(j<n){
            sum+=nums[j];
            int rem=sum-k;

            //already in the map 
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            //if sum is not in map then add it to mp
            if(mp.find(sum)==mp.end()){
                mp[sum]=1;
            }
            else{
            mp[sum]++;
            }
            j++;
        }
        return ans;
    }
};