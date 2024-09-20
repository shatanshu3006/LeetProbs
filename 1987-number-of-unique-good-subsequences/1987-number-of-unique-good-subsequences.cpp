class Solution {
public:
//  Every leading 1 can generate 1 + prev binary strings either ending with 0 or 1.
// Every 0 can generate prev binary strings ending with 0 and 1.
    int numberOfUniqueGoodSubsequences(string binary) {
        bool hasZero = false;
        int endWithZeroes=0,endWithOnes=0,mod=1e9+7;
        
        for(auto b:binary){
            if(b=='1'){
                endWithOnes = (endWithOnes + endWithZeroes + 1)%mod;
            }else{
                hasZero=true;
                endWithZeroes = (endWithOnes + endWithZeroes)%mod;
            }
        }
        
        return (endWithOnes + endWithZeroes + hasZero)%mod;
    }
};