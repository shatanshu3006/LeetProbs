class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int diff=abs(nums[i]-nums[n-i-1]);
            mp[diff]++;
        }

        int maxfreq=0;
        vector<int>maxval;
        for(auto it:mp){
            //sbse jyda bar konsa diff repeat ho rha hai wo maxval me store ho rha hai 
            // aur wo maxfreq update ho rhi hai ki koi diff bhot bar repeat ho rha hai
            if(it.second>=maxfreq){
                maxfreq=it.second;
                maxval.push_back(it.first);
            }
        }
        int opr=INT_MAX;

        for(int j=0;j<maxval.size();j++){
            int oprr=0;
            for(int i=0;i<n/2;i++){
                int diff=abs(nums[i]-nums[n-i-1]);
//(diff!=maxval[j]) are proving whether we have to change both nums[i] and nums[n-i-1] or our answer will be accepted by changing only one value as we want minimun operations.               
                if(diff!=maxval[j]){
                    if((min(nums[i],nums[n-i-1])+maxval[j]>k) && (max(nums[i],nums[n-i-1])-maxval[j]<0)){
                        oprr+=2;
                    }
                    else{
                        oprr++;
                    }
                }
            }
            opr=min(opr,oprr);
        }
        return opr;
    }
};