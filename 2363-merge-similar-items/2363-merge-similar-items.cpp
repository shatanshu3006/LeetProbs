class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums1[i][0])!=mp.end()){
                mp[nums1[i][0]]+=nums1[i][1];
            }
            else{
                mp[nums1[i][0]]=nums1[i][1];
            }
        }
        for(int i=0;i<m;i++){
            if(mp.find(nums2[i][0])!=mp.end()){
                mp[nums2[i][0]]+=nums2[i][1];
            }
            else{
                mp[nums2[i][0]]=nums2[i][1];
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};