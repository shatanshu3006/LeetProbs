class Solution {
public:
int func(int n){
    int cnt=0;
    for(int i=0;i<32;i++){
        if(n>>i & 1)cnt++;
    }
    return cnt;
}
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(func(i));
        }
        return ans;
    }
};