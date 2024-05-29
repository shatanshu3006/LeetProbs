class Solution {
public:
bool is_check(vector<int>&mp1,vector<int>&mp2){
    return mp1==mp2;
}
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int>mp1(26,0),mp2(26,0);

        //storing into mp1
        for(int i=0;i<n1;i++){
            mp1[s1[i]-'a']++;
        }

        //apply sliding window
        for(int i=0;i<n2;i++){
            if(i<n1){
                mp2[s2[i]-'a']++;
            }
            else{
                if(is_check(mp1,mp2)){
                    return true;
                }
                mp2[s2[i-n1]-'a']--;
                mp2[s2[i]-'a']++;
            }
        }
        if(is_check(mp1,mp2))return true;
        return false;
    }
};