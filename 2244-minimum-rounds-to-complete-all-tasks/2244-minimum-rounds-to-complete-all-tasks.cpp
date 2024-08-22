class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(auto it:tasks)mp[it]++;
        //store the ans for.3 cases
        int ans=0;
        for(auto it:mp){
            int freq=it.second;
            if(freq==1)return -1;

            else if(freq%3==0)ans+=freq/3;
            else if(freq%3==1 || freq%3==2){
                ans+=freq/3+1;
            }
        }
        return ans;
    }
};