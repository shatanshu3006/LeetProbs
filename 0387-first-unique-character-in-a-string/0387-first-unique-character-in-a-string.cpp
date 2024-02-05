class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>find;
        for(int i=0;i<s.size();i++){
            find[s[i]]=i;
        }
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        //making a collection of the ones occuring only once
        char ch='A';
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                ch=s[i];
                break;
            }
        }
        if(ch=='A')return -1;
        return find[ch];
        
    }
};