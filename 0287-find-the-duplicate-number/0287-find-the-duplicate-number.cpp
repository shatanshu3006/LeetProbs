class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);

        fast=nums[0];//reset the fast pointer
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;    //or return fast
    }
};