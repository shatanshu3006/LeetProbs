class Solution {
public:
bool good(vector<int>&quantities,int n,int mid){
    int cnt=0;
    for(auto it:quantities){
        cnt+=ceil((double)it/mid);
        if(cnt>n)return false;      //some products are still left to be distributed
        //since 0 product to some houses are allowed but some products remaining id not allowed
    }
    return true;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=*max_element(quantities.begin(),quantities.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(good(quantities,n,mid)==true){
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