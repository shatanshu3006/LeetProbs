class Solution {
public:
//just itereting from starting to end (mind it that its saying to choose maximum count so start to end or end to start it will be )
    int maxOperations(string s) {
        int ans=0,temp=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1')temp++;
            if(s[i]=='1' && s[i+1]=='0'){
                ans+=temp;
            }
        }
        return ans;
    }
};