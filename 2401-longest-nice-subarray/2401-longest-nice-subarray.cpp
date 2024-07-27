class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int num=0;
        int l=0; //behind i
        int ans=0;
        int r=0;
        while(r<n){
            while((num&nums[r])!=0){
                //probelm so we have to keep removing number from the back until this is solved as & of all pairs should be zero
    // for that we can simply do xor so it will unset the bits set by j
                num^=nums[l];
                l++;
            }
            //now if  & of num and nums[i] is zero we can se the bits of num with our current element 
            num |=nums[r];
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
    
};