class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlength=1;
        int count2=1,count1=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                count1++;
            }
            else{
                maxlength=max(count1,maxlength);
                count1=1;   //reset the counter
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count2++;
            }
            else{
                maxlength=max(maxlength,count2);
                count2=1;   //reset the counter
            }
        }
        //we initialised with maxlwnght=0 if had it not been updated thn we'd need to check for one final time
         maxlength=max(maxlength, count2);
        maxlength=max(maxlength, count1);
        return maxlength;
    }
};