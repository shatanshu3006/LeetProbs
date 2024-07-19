class Solution {
public:
bool ispossible(vector<int>&weights,int d,int mid){
    int days=1;
    int sum=0;
    for(int i=0;i<weights.size();i++){
        if(sum+weights[i]<=mid){
            sum+=weights[i];
        }
        else{
            sum=weights[i];    //us din ka ho gaya capacity
            days++;  //increasing days

        }
    }    
    if(days<=d){
        return true;
    }else{
        return false;
    }
}
    int shipWithinDays(vector<int>& weights, int days) {
        
// weights=[1,2,3,4,5,6,7,8,9,10] days=5
//search space -> [10,11,12,13,...,55] 
int maxi=-1;
int sum=0;
for(int i=0;i<weights.size();i++){
    maxi=max(maxi,weights[i]);
    sum+=weights[i];
}
int ans=-1;
int low=maxi;
int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(weights,days,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;

        }
    }
    return ans;
        
    }
};