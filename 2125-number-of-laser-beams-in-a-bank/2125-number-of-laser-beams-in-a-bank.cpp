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

            if(cnt!=0)v.push_back(cnt);
        }
        int sum=accumulate(v.begin(),v.end(),0);
        if(sum==0)return 0;
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans+=v[i]*v[i+1];
        }
        return ans;
    }
};