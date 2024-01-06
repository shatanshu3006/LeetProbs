class Solution {
public:
bool isEqual(string str,int i){
    str.erase(i,1);
    map<char,int>mp;

    for(int i=0;i<str.size();i++){
        mp[str[i]]++;
    }

    for(int i=1;i<str.size();i++){
        if(mp[str[i]]!=mp[str[i-1]])return false;
    }
    return true;
}
    bool equalFrequency(string word) {
        for(int i=0;i<word.size();i++){
            if(isEqual(word,i)==true)return true;
        }
        return false;
    }
};