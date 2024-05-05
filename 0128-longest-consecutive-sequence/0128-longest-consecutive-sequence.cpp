class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
        return nums.size();
        sort(nums.begin(),nums.end());
        int temp=1;
        int count=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)
            temp++;
            else if(nums[i]-nums[i-1]==0)
            continue;
            else{
            count=max(count,temp);
            temp=1;
            }
        }
        count=max(count,temp);
        return count;
    }
};