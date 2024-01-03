class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            v.push_back(cnt);
        }
        vector<int>num;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0)num.push_back(v[i]);
        }
        int sum=accumulate(v.begin(),v.end(),0);
        if(sum==0)return 0;
        int n=num.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=num[i]*num[i+1];
        }
        return ans;
    }
};