class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        string a,b;
        for(int i=0;i<n/2;i++){
            a+=s[i];
        }
        for(int i=n/2;i<n;i++){
            b+=s[i];
        }
int vow_a=0,vow_b=0;
        for(int i=0;i<n/2;i++){
            if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' ||a[i]=='u' || a[i]=='A' ||a[i]=='E' || a[i]=='I' ||a[i]=='O' || a[i]=='U'){
                vow_a++;
            }
            if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' ||b[i]=='u' || b[i]=='A' ||b[i]=='E' || b[i]=='I' ||b[i]=='O' || b[i]=='U'){
                vow_b++;
            }
            
            
        }
        return vow_a==vow_b;
    }
};