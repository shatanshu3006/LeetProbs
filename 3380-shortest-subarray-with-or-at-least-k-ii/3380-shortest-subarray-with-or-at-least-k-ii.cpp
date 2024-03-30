class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>bitCount(32);
        int leftIndex=0,currentNum=0,minLength=INT_MAX;

        for(int rightIndex=0;rightIndex<nums.size();rightIndex++){
            currentNum|=nums[rightIndex];
            incrementBitCount(bitCount,nums[rightIndex]);

            while(leftIndex<=rightIndex && currentNum>=k){
                minLength=min(minLength,rightIndex-leftIndex+1);
                decrementBitCount(bitCount,nums[leftIndex]);
                currentNum=formNumber(bitCount);
                leftIndex++;
            }
        }

        if(minLength==INT_MAX){
            return -1;
        }
        else{
            return minLength;
        }
    }
    void incrementBitCount(vector<int>&bitCount,int num){
        int index=0;
        while(num>0){
            if(num%2!=0){
                bitCount[index]++;
            }
            num>>=1;
            index++;
        }
    }
    void decrementBitCount(vector<int>&bitCount,int num){
        int index=0;
        while(num>0){
            if(num%2!=0){
                bitCount[index]--;
            }
            num>>=1;
            index++;
        }
    }
    int formNumber(vector<int>&bitCount){
        int formedNum=0;
        int powerOfTwo=1;
        for(int i=0;i<30;i++){
            if(bitCount[i]>=1){
                formedNum+=powerOfTwo;
            }
            powerOfTwo*=2;
        }
        return formedNum;
    }

};