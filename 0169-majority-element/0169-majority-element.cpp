class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
            }
            if(element==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                count1++;
            }
        }
        if(count1>floor(nums.size()/2)){
            return element;
        }
        return -1;
    }
};