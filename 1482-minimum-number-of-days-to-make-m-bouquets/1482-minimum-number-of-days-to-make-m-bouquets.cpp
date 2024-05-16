class Solution {
public:
    bool good(vector<int>&bloomDay,int mid,int m,int k){
        int cnt=0;
        int n=0;
        for(int i=0;i<bloomDay.size();i++){
           if (bloomDay[i]<=mid){
               n++;
           }
           else{
               n=0;
           }
           if(n==k){
               cnt++;
               n=0;
           }
        }
        if(cnt<m){
            return false;
        }
        else{
            return true;
        }
    }
    // did a binary search on values from least to largest element of the vector
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (long long)m * k)
            return -1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=e;
        while(s<=e){
            int mid=(s+e)/2;
            if(good(bloomDay,mid,m,k)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};