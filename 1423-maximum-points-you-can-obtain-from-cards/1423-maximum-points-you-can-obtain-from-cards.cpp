class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        
        int total_sum=0;
       for(int i=0;i<n;i++){
        total_sum+=cardPoints[i];
       }
       if(n==k){
            return total_sum;
        }
        
        int min_sum=INT_MAX;
        // hit a length of n-k for subarray first 
        int left=0,right=0;
        int sum=0;
        while(right<n){
            sum+=cardPoints[right];
            if(right-left+1==(n-k)){ //hit
                min_sum=min(min_sum,sum);
                sum-=cardPoints[left];  //slide the window
                left++;
            }
            
            right++;
        }
        
        return (total_sum-min_sum);


    }
};