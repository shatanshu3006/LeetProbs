class Solution {
public:
//check for the first part and then later on using loops
    //since the hash for i+1 need previous value of i but for the first window we do not have one so we handle this separately by check ing then later we use for loop from the index starting from the pattern length (len)
typedef unsigned long long int ull;
    int strStr(string haystack, string needle) {
        //using rabin karp
        //TC: O(n+m)
        //SC: O(1)

        return rabinKarp(haystack,needle);
    }

    int rabinKarp(string &s,string &pat)
    {   
        // TC: O(m+n)
        // SC: O(1)
        
        ull power = 1;
        ull p = 131;
        ull hash1 = 0, hash2 = 0;
        
        int len = pat.length();
        for(int i = 1;i<len;i+=1)
            power*=p;
            
        for(int i = 0;i<len;i+=1)
        {
            hash1 = hash1*p + pat[i];
            hash2 = hash2*p + s[i];
        }
        
        if(hash1==hash2)
            return 0;
        
        
        for(int i = len;i<s.length();i+=1)
        {
            hash2 -= power*s[i-len];
            hash2 = hash2*p + s[i];
            
            if(hash2==hash1)
                return i-len+1;
            
        }
        
        return -1;
    }
};