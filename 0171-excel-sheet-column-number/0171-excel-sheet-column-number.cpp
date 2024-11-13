class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(int i=0;i<columnTitle.length();i++){
            char ch=columnTitle[i];
            int x=ch-'A'+1;
            ans=ans*26+x;
        
        }
        return ans;
    }
};