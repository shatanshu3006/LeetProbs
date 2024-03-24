class Solution {
public:
    int minOperations(int k) {
        int ans=0;
        int s=sqrt(k);
        ans+=(s-1);
        int val=ceil((float)k/s)-1;
        ans+=val;
        return ans;
    }
};