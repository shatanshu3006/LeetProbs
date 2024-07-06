class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // repeat the arry till k 
        for(int i=0;i<k;i++){
            colors.push_back(colors[i]);
        }
        int ans=0,l=0,n=colors.size();

        for(int i=0;i<n-1;i++){
            if(colors[i]==colors[i+1]){
                l=i;
            }
            if(i-l+1>=k){
                ans++;
            }
        }
        return ans;
    }
};