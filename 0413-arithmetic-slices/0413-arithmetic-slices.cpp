class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i=0;
        int j=2;
        if(nums.size()<3){
            return 0;
        }
        int diff=nums[1]-nums[0];
        int ans=0;
        while(j<nums.size()){
            if(nums[j]-nums[j-1]==diff){
                //if its an arithmetic sequence, then length>=3
                //and add the length to the ans as that whole array is arithmetic
                if(j-i+1>=3){
                    ans=ans+(j-i-1);
                }
                j++;
            }
            else{
                //shrink the window to j-1;
                diff=nums[j]-nums[j-1];
                i=j-1;
                j++;
            }
            
        }
        return ans;
    }
};