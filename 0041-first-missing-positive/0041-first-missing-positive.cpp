class Solution {
public:
//cyclic sort concept
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        //use cycle sort to replace the positive elements smaller than n at
        //correct index

        int i=0;
        while(i<n){
            //we are only swapping and moving the positive elements!
            if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }

        //iterate through nums
        //return smallest missing positive integer

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }

        //if all elements are at their correct indices 
        //smallest missing integer is n+1

        return n+1;

    }
};