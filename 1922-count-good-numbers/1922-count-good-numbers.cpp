class Solution {
    //Let observe something for n = 5.
// Options : 5 4 5 4 5
// Position : 0 1 2 3 4
// So, our answer will be (5 x 4) x (5 x 4) x 5
// This can be seen as we have 20 options for every n/2 positions if we group positions in 2.
// Since we are following 0-indexing ==> last position will be even for odd n and will have 5 options.

// For even n we will have perfectly n/2 groups each having 20 options.

// Thus we first find out 20^(n/2). If n is odd multiply it by 5. Then return.

// For calculating power we will use recursive binary exponentiation.
public:
    int M = 1e9+7;
    long long power(long long b, long long e, long long ans) {
        if(e == 0) return ans;
        if(e & 1) return power(b, e - 1, (ans * b) % M);
        else return power((b * b) % M, e / 2, ans);
    }
    int countGoodNumbers(long long n) {
        long long temp=power(20,n/2,1);
        if(n%2==1){
            return (temp*5)%M;
        }
        else{
            return temp;
        }
    }
};