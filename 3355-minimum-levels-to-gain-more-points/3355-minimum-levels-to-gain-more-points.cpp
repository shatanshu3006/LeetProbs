class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        vector<int>prefixSum(n);
        if(possible[0]==1){
            prefixSum[0]=1;
        }
        else{
            prefixSum[0]=-1;
        }

        for(int i=1;i<n;i++){
            if(possible[i]==1){
                prefixSum[i]=prefixSum[i-1]+1;
            }
            else{
                prefixSum[i]=prefixSum[i-1]-1;
            }
        }
//for optimal playing , daniel has to leave atleast one last position 
//so daniel can in worst case travel till i==n-2 or i<n-1
        for(int i=0;i<n-1;i++){
            int daniel=prefixSum[i];
            int bob=prefixSum[n-1]-daniel;
            if(daniel>bob){
                return i+1;
            }
        }
        return -1;
    }
};