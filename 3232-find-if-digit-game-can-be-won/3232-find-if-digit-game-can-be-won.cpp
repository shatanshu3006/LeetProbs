class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int singlesum=0,doublesum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=10)doublesum+=nums[i];
            else singlesum+=nums[i];
        }
        if(singlesum==doublesum)return false;
        else{
            return true;
        }
    }
};