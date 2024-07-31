class Solution {
public:
bool isPossible(int mid,vector<int>&nums,int maxOps){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]%mid==0){
            count+=(nums[i]/mid)-1;
        }
        else{
            count+=(nums[i]/mid);
        }
    }
    if(count>maxOps){
        return false;
    }
    return true;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,maxOperations)==true){
                ans=mid;
                high=mid-1; //find for even lower values
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};