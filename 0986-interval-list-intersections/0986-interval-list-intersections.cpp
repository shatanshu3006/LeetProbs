class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int n1=nums1.size(),n2=nums2.size();
    int i=0,j=0;
        while(i<n1 && j<n2){
            int a=nums1[i][0],b=nums1[i][1],c=nums2[j][0],d=nums2[j][1];

            if(d<a || b<c){
                if(b<d)i++;
                else j++;
            }
            else{
                //there is an overlap
                int overlap_left=max(a,c),overlap_right=min(b,d);
                ans.push_back({overlap_left,overlap_right});

                //decide which one to move right
                if(b<d)i++;
                else j++;
            }
        }
        return ans;
    }
};