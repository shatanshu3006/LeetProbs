class Solution {
public:
    int captureForts(vector<int>& forts) {
        int l=0,r=0,maxlen=0,n=forts.size();
        if(n==0 || n==1){
            return 0;
        }
        while(r<n){
            if(forts[l]==0){    //if encounter 0 move i
                l++;
            }

            if((forts[r]==1 && forts[l]==-1) || (forts[r]==-1 && forts[l]==1)){
                maxlen=max(maxlen,r-l-1);//we do j-i-1 because we want the count of 0's between 1 and -1 and vice versa
             
                l=r;//then we update our i
            }

            if(forts[l]==forts[r]){ //for cases where we have 0's between 1 and 1 or -1 and -1 
              
                l=r;
            }
            r++;
            
        }
        return maxlen;
    }
};