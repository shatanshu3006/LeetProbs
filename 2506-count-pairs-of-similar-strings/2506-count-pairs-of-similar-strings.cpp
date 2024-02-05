class Solution {
public:
bool check(string s1,string s2){
    set<char>set1,set2;
    string ans1,ans2;
    for(auto it:s1){
        set1.insert(it);
    }
    for(auto it:s2){
        set2.insert(it);
    }
    for(auto it:set1){
        ans1+=it;
    }
    for(auto it:set2){
        ans2+=it;
    }
    return ans1==ans2;
}
    int similarPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(words[i],words[j])==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};