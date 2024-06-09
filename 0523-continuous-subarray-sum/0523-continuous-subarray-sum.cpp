class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //instead of sums, this works on the remaninder sfound till that index when the sum id divided by k
        map<int,int>remaindersFound;
        int currSum=0;
        remaindersFound[0]=-1;  // to handle the initla case when the subarray starts from the first index (we are keeping it -1)

        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int rem=currSum%k;

            if(remaindersFound.find(rem)!=remaindersFound.end()){
                //check if the length is atleast 2
                if(i-remaindersFound[rem]>=2){
                    return true;
                }
            }
            
              else  remaindersFound[rem]=i;
            
        }
        return false;
    }
};