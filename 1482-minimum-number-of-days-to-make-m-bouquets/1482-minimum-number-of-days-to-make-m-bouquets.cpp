class Solution {
public:
bool good(vector<int>&bloomDay,int mid,int m,int k){
    int cnt=0;
    int n=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
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
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        int n=bloomDay.size();
        if(n<(long long)m*k)return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(good(bloomDay,mid,m,k)==true){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};