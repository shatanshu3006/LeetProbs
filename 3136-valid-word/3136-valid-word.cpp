class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n<3){
            return false;
        }
        int v=0,c=0;
        for(auto it:s){
            if(isalpha(it)){
                if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')
                    v++;
                else if(it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
                    v++;
                else
                    c++;
            }
            if(!(isalpha(it) || isdigit(it))){
                return false;
            }
        }
        if(v>=1 && c>=1){
            return true;
        }
        return false;
    }
};