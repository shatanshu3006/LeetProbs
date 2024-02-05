class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fre(128, 0);
        int cnt = 0;
        for(auto it:t) {
            fre[it-'A']++;
            if(fre[it-'A']==1) cnt++;
        }
        int ans = INT_MAX, ind = -1;
        int i=0, j=0;
        while(j<s.length()){
            fre[s[j]-'A']--;
            if(fre[s[j]-'A']==0) cnt--;
            while(i<=j && cnt==0){
                fre[s[i]-'A']++;
                if(fre[s[i]-'A']>0) cnt++;
                if(ans>(j-i+1)){
                    ans = j-i+1;
                    ind = i;
                }
                i++;
            }
            j++;
        }
        // cout<<ans<<endl;
        if(ind==-1) return "";
        return s.substr(ind, ans);
    }
};