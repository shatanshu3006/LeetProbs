class Solution {
public:
string solve(int n){
    string s;
    while(n>0){
        s=to_string(n%2)+s;
        n=n/2;
    }
    return s;
}
    string convertDateToBinary(string date) {
        string ans;
        ans+=solve(stoi(date.substr(0,4)));
        ans+='-';
        ans+=solve(stoi(date.substr(5,7)));
        ans+='-';
        ans+=solve(stoi(date.substr(8,10)));
        return ans;
    }
};