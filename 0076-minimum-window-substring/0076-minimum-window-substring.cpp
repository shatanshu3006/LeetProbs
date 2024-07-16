class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        vector<int>freq(128,0);
        int cnt=0;
        //calculating the total number of unique chars in t
        for(auto it:t){
            freq[it-'A']++;
            if(freq[it-'A']==1)cnt++;
        }
        int ans=INT_MAX,ind=-1;
        int i=0,j=0;
        while(j<n){
            freq[s[j]-'A']--;
            if(freq[s[j]-'A']==0)cnt--;
            while(i<=j && cnt==0){
                freq[s[i]-'A']++;
                if(freq[s[i]-'A']>0)cnt++;
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    ind=i;
                }
                i++;
            }
            j++;
        }
        if(ind==-1)return "";
        return s.substr(ind,ans);

    }
};