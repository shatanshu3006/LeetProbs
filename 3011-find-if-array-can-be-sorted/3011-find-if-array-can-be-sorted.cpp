class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(nums[j]>nums[j+1]){
                    if(__builtin_popcount(nums[j])!=__builtin_popcount(nums[j+1])){
                        return false;
                        
                    }
                    //otherwise we carry on our bubble sorting
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return true;
    }
};