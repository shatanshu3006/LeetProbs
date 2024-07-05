class Solution {
public:
        // FLoyd's hare and tortoise approach (like in linked list for cycle detection)
        //SLOW AND FAST POINTER APPROACH
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];//initialise the slow pointer 
        int fast=nums[0];//initialise the fast pointer 
        //the concept is to checkc if the traversal makes aclosed cylye as explained by striver!!.
        // if there is a duplicate element, then we can easily confirm that they will meet at that point.

        do{
            slow=nums[slow];
            fast=nums[nums[fast]]; //fast pointer moves faster.
        }
        while(slow!=fast);
        fast=nums[0]; //initialise again 
        while(slow!=fast){
            slow=nums[slow]; //now move them the same speed (a-x+x=a)
            fast=nums[fast]; //now move them the same speed 
        }
        return slow; //or return fast;
        
    }
};