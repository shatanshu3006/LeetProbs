class Solution {
public:
bool find(vector<int>&mp,int start,int end){
    int n=mp.size();
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(mp[mid]<start){
            l=mid+1;
        }
        else{
            if(mp[mid]>end){
                r=mid-1;
            }
            else{
                return true;
            }
        }
    }
    return false;
}
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        //map to store all the indices of same parity
        vector<int>mp;
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]%2==0 && nums[i+1]%2==1)||(nums[i]%2==1 && nums[i+1]%2==0)){
                continue;
            }
            else{
                mp.push_back(i);
            }
        }
        vector<bool>ans;
        for(auto it:queries){
            int start=it[0],end=it[1];
            if(find(mp,start,end-1)){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};