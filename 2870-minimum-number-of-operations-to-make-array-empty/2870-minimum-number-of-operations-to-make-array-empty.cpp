class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int>arr;
        int ans=0;
        for(auto it:mp)arr.push_back(it.second);
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=1)return -1;
            else if(arr[i]%3==0)ans+=arr[i]/3;
            else if(arr[i]%3==1 || arr[i]%3==2){
                ans+=(arr[i]/3 +1);
            }
        }
        return ans;
    }
};