class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute force O(N) solution 
        //gives TLE
        /*
        int n=height.size();
        int ans=0;
        int right=n-1;

        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
                int area;
                area=(r-l)*(min(height[l],height[r]));
                ans=max(ans,area);
            }
        }
        return ans;
        */

        //optimized solution 
        int ans=0;
        int left=0;
        int n=height.size();
        int right=n-1;
        while(left<right){
            int area=(right-left)*(min(height[left],height[right]));
            ans=max(ans,area);
            if(height[left]<height[right]){
                left++;
            }
            else if(height[right]<height[left]){
                right--;
            }
            //in case both equal,we need to check further 
            //so derement right or increment left , do any one
            else{
                right--;
            }
        }
        return ans;
    }
};