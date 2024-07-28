class Solution {
public:
    int numberOfSubstrings(string s) {
        int output=0;
        int ans=0;
        vector<int>prefix(s.length(),0);
        for(int i=0;i<s.length();i++){
            if(i==0){
                prefix[i] = (s[i] == '1') ? 1 : 0;
            }
            else{
                prefix[i]=prefix[i-1]+((s[i]=='1')?1:0);
            }
        }
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                int ones=prefix[j]-((i==0?0:prefix[i-1]));
                int zeroes=(j-i+1)-ones;

                if(ones>=zeroes*zeroes){
                    ans++;
                    int k=sqrt(ones);

                    if(k>zeroes){
                        ans+=(j+(k-zeroes)>=s.length()?(s.length()-j-1):(k-zeroes));
                    }
                    j+=(k-zeroes);
                }
                else{
                    j+=(zeroes*zeroes-ones-1);
                }
            }
        }
        return ans;
    }
};