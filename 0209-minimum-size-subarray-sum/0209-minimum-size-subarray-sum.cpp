class Solution {
public:
bool windowfind(int lenofwindow,vector<int>&nums,int target){
    int l=0,r=0,sum=0,mx=INT_MIN;
    int n=nums.size();
    while(r<n){
        sum+=nums[r];
        if(r-l+1==lenofwindow){
            mx=max(mx,sum);
            sum-=nums[l];
            l++;
        }
        r++;
    }
    if(mx>=target){     //we have found sum greater than target with the window size of lenofwindow so its true
        return true;
    }
    return false;
}
    int minSubArrayLen(int target, vector<int>& nums) {
        //O(nlogn) solution -> binary search 
        //search space is the window length anf then we do fixed length sliding window

        int low=1,high=nums.size(),ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(windowfind(mid,nums,target)==true){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};