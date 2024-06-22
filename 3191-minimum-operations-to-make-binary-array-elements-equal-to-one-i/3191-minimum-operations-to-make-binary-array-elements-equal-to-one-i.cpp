class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),res=0;
        for(int i=0;i<n-2;i++){
            //element is 0
            if(nums[i]==0){
                //flip all three if the element found is 0
                for(int j=i;j<i+3;j++){
                    nums[j]^=1;
                }
                res++;
            }
        }

        if(nums[n-1]==0 || nums[n-2]==0){
            return -1;
        }
        else{
            return res;
        }
    }
};