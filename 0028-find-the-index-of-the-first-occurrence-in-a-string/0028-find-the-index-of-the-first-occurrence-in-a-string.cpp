class Solution {
public:
//using kmp algorithm

//TC: O(m+n)
//SC: O(m)
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
    int kmp(string &s, string &pat)
    {   
        // TC: O(m+n)
        // SC: O(m)
        
        int n = s.length();
        int m = pat.length();
        
        vector<int> pi(m,0);
        
        for(int i = 1;i<m;i+=1)
        {
            int j = pi[i-1];
            
            while(j>0 and pat[i]!=pat[j])
                j = pi[j-1];
            
            
            if(pat[i]==pat[j])
                j+=1;
            
            pi[i] = j;
            
        }

        int j = 0;
        int i = 0;
        while(i<n)
        {
            if(s[i]==pat[j])
            {
                i+=1;
                j+=1;
                if(j==m)
                    return i-j;
                
            }
            
            else
            {
                if(j)
                    j = pi[j-1];
                else
                    i+=1;
            }
 
        }
        
        
        return -1;
    }
};