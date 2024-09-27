class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;

        int n=nums.size();
        for(int i=0;i<n;i++){
            //maintaining the size of the window
            //using the dequeue to remove elem from the front
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //doing the stack functionality by popping back form dequeue
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;
    }
};