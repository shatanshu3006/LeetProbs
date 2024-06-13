class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; //character to map index
        int r=0,l=0,maxi=0;
        while(r<s.length()){
            if(st.find(s[r])==st.end()){   //element not in window
                    st.insert(s[r]);
                    maxi=max(maxi,r-l+1);
                    r++;
            }
            else{
                st.erase(s[l]);
                l++; //element in window
            }
        }
        return maxi;
    }
};