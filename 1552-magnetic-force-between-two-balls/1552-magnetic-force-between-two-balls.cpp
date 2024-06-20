#define ll long long int
class Solution {
private:
    bool possible(vector<int>&nums, int m, ll mid){
        int pre = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - pre >= mid) cnt++, pre = nums[i];
            if(cnt == m) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll s = 0, e = nums[n-1] - nums[0];
        ll ans = 0;
        while(s <= e){
            ll mid = s + (e-s)/2;
            if(possible(nums, m, mid)){
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
        } 
        return ans;
    }
};