class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans=0,leftptr=0,count=1;
        for(int i=1;i<word.size();i++){
            if(word[i-1]<word[i])count++;
            else if(word[i-1]>word[i]){
                leftptr=i;count=1;
            }

            if(count==5)ans=max(ans,i-leftptr+1);
        }
        return ans;
    }
};