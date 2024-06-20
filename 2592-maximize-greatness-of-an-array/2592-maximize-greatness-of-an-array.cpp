class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0,i=0,j=1;

        while(j<n){
            if(nums[j]>nums[i]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};