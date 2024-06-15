class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                //we do not increment mid as nums[high] can be 1 or 0
                // then we do not excatly know to increase the mid or keep it the same
                high--;
            }
        }
        return ;
    }
};