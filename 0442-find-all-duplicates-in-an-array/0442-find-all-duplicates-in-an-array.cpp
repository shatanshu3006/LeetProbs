class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            if(nums[index]<0){  //if number is negative it means we have seen this before
            result.push_back(index+1);

            }
            else{
                //mark the number as visited
                nums[index]=-nums[index];
            }
        }
        return result;
    }
};