class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        int n=b.size(),m=p.size(),j=0,ans=0,prev=0;

        sort(b.begin(),b.end());
        sort(p.begin(),p.end());

        for(int i=0;i<n;i++){
            int count=0;
            while(j<m && p[j]<=b[i] && count<capacity){
                if(p[j]-prev>1){
                    ans=p[j]-1;
                }
                prev=p[j];
                j++;
                count++;
            }
            if(count<capacity && b[i]-prev>=1){
                ans=b[i];
            }
        }
        return ans;
    }
};