class Solution {
public:
    
    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!needle || *needle == '')
            return haystack;
        char *p1 = haystack, *p2 = needle;
        while(p1){
            char *p1Begin = p1;
            p2 = needle;
            while(p1 && p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(*p2 == '\0'){
                return p1Begin;
            }
            p1 = p1Begin+1;
        }
    }
};