class Solution {
public:
bool isPrime(int n){
if (n <= 1)
return false;
if (n <= 3)
return true;
if (n % 2 == 0 || n % 3 == 0)
return false;
for (int i = 5; i * i <= n; i = i + 6){
if (n % i == 0 || n % (i + 2) == 0)
return false;
}
return true;
}
    int nonSpecialCount(int l, int r) {
        //find primes upto sqrt of r
        int lim=(int)sqrt(r);
        vector<bool>v(lim+1,true);
        v[0]=v[1]=false; //0 and 1 are not primes

        for(int i=2;i*i<=lim;i++){
            if(v[i]==true){
                for(int j=i*i;j<=lim;j+=i){
                    v[j]=false;
                }
            }
        }

        int cnt=0;
        for(int i=2;i<=lim;i++){
            if(v[i]){
                int sq=i*i;
                if(sq>=l && sq<=r){
                    cnt++;
                }
            }
        }
        return r-l+1-cnt;
    }
};