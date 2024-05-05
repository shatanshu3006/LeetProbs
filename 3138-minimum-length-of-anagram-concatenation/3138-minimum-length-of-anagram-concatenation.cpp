class Solution {
public:
vector<int>findDivisors(int n){
    vector<int>divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            divisors.push_back(i);

            if(i!=n/i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    return divisors;
}
    int minAnagramLength(string s) {
        int n=s.length();
        vector<int>divisors=findDivisors(n);

        for(auto it:divisors){
            vector<int>freq(26,0);
            bool isPossible=true;

            for(int i=0;i<n;i+=it){
                if(i==0){
                    for(int j=0;j<it;j++){
                        freq[s[i+j]-'a']++;
                    }
                }
                else{
                    vector<int>curr(26,0);
                    for(int j=0;j<it;j++){
                        curr[s[i+j]-'a']++;
                    }

                //now comparing the first segment with others
                    for(int k=0;k<curr.size();k++){
                        if(freq[k]!=curr[k]){
                            isPossible=false;
                        }
                    }
                }
            }
            //got a match finally after total traversal ,and not getting false
            //then return the least value of divisor as we are traversing the sortedlist
            if(isPossible==true){
                return it;
            }
        }
        //returning n is the largest divisor of the total n 
        //means all the chars are unique
        return n;
    }
};