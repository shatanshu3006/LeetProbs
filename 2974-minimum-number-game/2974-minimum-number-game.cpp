class Solution {
public:
//using priority queue
//tc->o(nlogn)
//sc->o(1)
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int i=0;
        while(pq.size()>0){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            nums[i++]=b;
            nums[i++]=a;
        }
        return nums;
    }
};