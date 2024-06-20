class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.size(),m=typed.size();
        if(m<n)return false;
        int i=0,j=0;
        while(i<n){
            if(name[i]==typed[j]){
                i++;j++;
            }
            else{
                if(j-1<0)return false;
                if(typed[j-1]!=typed[j]){
                    return false;
                }
                j++;
            }
        }
        while(j<m){
            if(typed[j]!=name[n-1]){
                return false;
            }
            j++;
        }
        return true;
    }
};