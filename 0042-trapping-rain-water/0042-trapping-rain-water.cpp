class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int water=0;
        int maxleft=0,maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft){
                    maxleft=height[left];
                }
                else{
                    water+=(maxleft-height[left]);
                    
                }
                left++;
            }
            else{
                if(height[right]>=maxright){
                    maxright=height[right];
                }
                else{
                    water+=(maxright-height[right]);
                    
                }
                right--;
            }
        }
        return water;
    }
};