class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            //sum is decremented if we get 0 and incremented if we get 1 
            //so if sum is zeero then the numberif zeroes and ones encountererd till now in subarray are equal
            if(nums[i]==0){
                sum--;
            }
            else{
                sum++;
            }
            //if sum==0 then ans is till this index
            if(sum==0){
                ans=i+1;
            }
            //if we had this sum before, then there was a subarray till this index
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }
            mp[sum]=i;

        }
        return ans;
    }
};