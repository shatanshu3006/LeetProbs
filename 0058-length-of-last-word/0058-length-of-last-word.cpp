class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int len=0;

// Extract each word from the stringstream
        while(ss>>word){
            len=word.size();   // store the length inthe last iteration before exiting loop
        }
        return len;
    }
};