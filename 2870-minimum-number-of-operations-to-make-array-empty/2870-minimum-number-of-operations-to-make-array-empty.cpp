class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a: nums){
            mp[a]++;
        }

        int count=0;
        for(auto a: mp){
            int t = a.second;
            if(t<2)return -1;
            if(t%3==0){
                count+=t/3;
            }
            else if(t%3==2){
                count+=(t-2)/3+1;
            }
            else if(t%3==1){
                count+=(t-1)/3+1;
            }
        }
        return count;
    }
};