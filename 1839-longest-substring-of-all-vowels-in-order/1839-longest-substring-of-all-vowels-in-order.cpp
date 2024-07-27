class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string need="aeiou";
        int ans=0,n=word.size();
        int l=0,r=0,curr=0;
        while(r<n){
            if(word[r]==need[curr]){
                while(word[r]==need[curr]){
                    r++;
                }
                curr++;
                if(curr==5)ans=max(ans,r-l);
            }
            else{
                curr=0;
                while(r<n && word[r]!=need[curr]){
                    r++;
                }
                l=r;
            }
        }
        return ans;
    }
};