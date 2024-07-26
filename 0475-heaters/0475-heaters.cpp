class Solution {
public:
bool check (vector<int>& houses, vector<int>& heaters,int mid){
    bool found=true;
    for(int i=0;i<houses.size();i++){
        auto it1=lower_bound(heaters.begin(),heaters.end(),houses[i]-mid);
        if(it1==heaters.end()){
            return false;
        }
        if(*it1>houses[i]+mid){
            return false;
        }
    }
    return true;
}
    int findRadius(vector<int>& houses, vector<int>& heaters) {
     sort(houses.begin(),houses.end());
     sort(heaters.begin(),heaters.end());
     int low=0,high=INT_MAX;
     int ans=INT_MAX;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(check(houses,heaters,mid)==true){
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