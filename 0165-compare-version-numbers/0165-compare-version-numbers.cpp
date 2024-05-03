class Solution {
public:
void parseVersion(const string& version, vector<int>& nums) {
    istringstream iss(version);
    string token;
    while (getline(iss, token, '.')) {
        nums.push_back(stoi(token));
    }
}
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        parseVersion(version1,v1);
        parseVersion(version2,v2);

        int diff = v1.size() - v2.size();
    if (diff > 0) {
        v2.insert(v2.end(), diff, 0);
    } else if (diff < 0) {
        v1.insert(v1.end(), -diff, 0);
    }

        // for(auto it:v1){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:v2){
        //     cout<<it<<" ";
        // }
        
        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                return 1;
                break;
            }
            if(v2[i]>v1[i]){
                return -1;
                break;
            }
        }
        return 0;


    }
};