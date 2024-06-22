class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n=nums.size();
         int i=0,ans=0,temp=0;
         while(i<n){
            if((nums[i]+temp)%2==0){
                ans++;
                temp++;
            }
            i++;
         }
         return ans;
    }
};