class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]==s[end]){
                while(s[start]==s[start+1] && start<end){
                    start++;
                }
                while(s[end]==s[end-1] && start<end){
                    end--;
                }
                //once the shrinking is done, move start and end by 1 unit 
                //for next iteration
                start++;
                end--;
            }
            else{
                break;
            }

        }
        int ans=end-start+1;
        if(ans<0)return 0;
        return ans;
    }
};