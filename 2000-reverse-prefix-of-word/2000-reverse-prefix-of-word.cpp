class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        int ind1=0;
        int ind2=-1;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                ind2=i;
                break;
            }
        }
        if(ind2==-1){
            return word;
        }
        
        int ind3=ind2+1;
        string ans="";
        for(int i=ind2;i>=0;i--){
            ans+=word[i];
        }
        for(int i=ind3;i<n;i++){
            ans+=word[i];
        }
        return ans;
    }
};