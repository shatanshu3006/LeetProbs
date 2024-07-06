class Solution {
public:
typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        ll res=0,andd;

        map<ll,ll>mp1;
        for(int i=0;i<n;i++){
            map<ll,ll>mp2;
            if(k==nums[i]){
                res++;
            }
            mp2[nums[i]]=1;
            for(auto it:mp1){
                andd=it.first&nums[i];
                if(k==andd){
                    res+=it.second;
                }
                mp2[andd]+=it.second;
            }
            mp1=mp2;
        }
        return res;
        
    }
};