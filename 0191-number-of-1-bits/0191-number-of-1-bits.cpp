class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            
            //checking the last bit
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};
// In this code we took the binary representation of the entered number and
// made right shifts to the number until we got all the bits zero.
// increase the counter for the number of times the right shift is made and that
// is the answer.