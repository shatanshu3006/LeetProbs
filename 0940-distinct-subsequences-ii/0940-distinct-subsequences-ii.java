class Solution {
    static int mod=1000000007;
    public int distinctSubseqII(String str) {
        int[]dp=new int[str.length()+1];
        dp[0]=1;
        HashMap<Character,Integer>lo=new HashMap<>();

        for(int i=1;i<dp.length;i++){
            dp[i]=(2*(dp[i-1])%mod)%mod;
            dp[i]=dp[i]%mod;
            char ch=str.charAt(i-1);
            if(lo.containsKey(ch)){
                int j=lo.get(ch);
                dp[i]=(((dp[i])%mod-(dp[j-1])%mod)+mod)%mod;
                dp[i]=dp[i]%mod;
            }
            lo.put(ch,i);
        }
        return ((dp[str.length()])%mod-1 + mod)%mod;
    }
}