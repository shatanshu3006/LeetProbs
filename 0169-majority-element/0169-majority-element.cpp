class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int iterations = 4;
        srand(time(NULL));
        int n = nums.size();
        for(int i = 0; i < iterations; i++){
            int randomIndex = rand() % n;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[randomIndex]){
                    cnt++;
                }
            }
            if(cnt > n / 2){
                return nums[randomIndex];
            }
        }
        return 1e9 + 1;
    }
};