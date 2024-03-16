typedef long long ll;
class Solution {
public:

//insert all items to a min heap priority queue( smallest value at top )
// Also evaluate the total sum of the array nums
// Iterate over queries and then keep on setting 0 as per the query

    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<ll>ans;
        ll sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i=0;i<nums.size();i++){
            sum+=nums[i];
            pq.push({nums[i],i});
        }

        for(auto q:queries){
            sum-=nums[q[0]];    //reducing the value from total sum
            nums[q[0]]=0;   //changing the value to 0

            while(pq.size() && q[1]){
                //removing the top k elements
                //even if the number of elements is less than k 
                //then pq.size() takes care of it
                if(nums[pq.top().second]){
                    sum-=nums[pq.top().second];
                    nums[pq.top().second]=0;
                    q[1]--;
                }
                pq.pop();
            }
            ans.push_back(sum);
        }
        return ans;
        
        
    }
};