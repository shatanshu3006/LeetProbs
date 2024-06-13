class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int,int>mp;
        int p=k;
        int i=0;
        int j=0;
        int n=nums.size();
        int maxi=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[0]>k){
                mp[nums[i]]--;
                i++;
            }
            maxi=max(maxi,j-i +1);
            j++;
            
        }
        return maxi;
    }
};